/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:36:51 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/03 22:48:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	4 = hypothenuse, escape value	*/
int	burningship(t_fractol *f, int x, int y)
{
	int			it;
	t_complex	z;
	t_complex	c;

	ft_memset(&z, 0, sizeof(t_complex));
	ft_memset(&c, 0, sizeof(t_complex));
	c.r = scale(x, f->idx.xmin, f->idx.xmax, WIN_WIDTH);
	c.i = scale(y, f->idx.ymin, f->idx.ymax, WIN_HEIGHT);
	it = 0;
	while (it < f->max_it)
	{
		if (((z.r * z.r) + (z.i * z.i) > 4))
			break ;
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		z = sum(z_square(z), c);
		it++;
	}
	return (it);
}
