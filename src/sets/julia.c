/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:35:54 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/30 17:26:01 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/*	Its point of interest is z, and c is a constant	*/
int	julia(t_fractal *f, int x, int y)
{
	int			it;
	t_complex	z;
	t_complex	c;

	ft_memset(&z, 0, sizeof(t_complex));
	ft_memset(&c, 0, sizeof(t_complex));
	z.r = scale(x, f->idx.xmin, f->idx.xmax, WIN_WIDTH);
	z.i = scale(y, f->idx.ymax, f->idx.ymin, WIN_HEIGHT);
	c.r = f->julia_c.r;
	c.i = f->julia_c.i;
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
