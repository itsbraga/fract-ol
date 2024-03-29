/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:36:46 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/29 20:11:40 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/*	Its point of interest is c, and z = 0	*/
int	mandelbrot(t_data *f, int x, int y)
{
	int			it;
	t_complex	z;
	t_complex	c;

	memset4struct(&z, 0, sizeof(t_complex));
	memset4struct(&c, 0, sizeof(t_complex));
	c.r = scale(x, f->idx.xmin, f->idx.xmax, WIN_WIDTH);
	c.i = scale(y, f->idx.ymax, f->idx.ymin, WIN_HEIGHT);
	it = 0;
	while (it < f->max_it)
	{
		if (((z.r * z.r) + (z.i * z.i) > f->esc_value))
			break ;
		z = sum(z_square(z), c);
		it++;
	}
	return (it);
}
