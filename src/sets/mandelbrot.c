/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:36:46 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/31 22:51:55 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/*
	Mandelbrot uses 0 as a starting value for z.r and z.i, and
	adds pixel coordinates (c.r and c.i) every time it iterates.

	Its formula iterates over complex numbers.
	At every iteration, Z is squared.
        z = z * z + c
	
	If the result tends toward infinity, that means it is not part of
    the set.
	If the result stays small over several iterations, the number
    is part of the set.

	4 = hypothenuse, escape value
*/
int	mandelbrot(t_fractol *f, int x, int y)
{
	int			it;
	t_complex	z;
	t_complex	c;

	ft_memset(&z, 0, sizeof(t_complex));
	ft_memset(&c, 0, sizeof(t_complex));
	c.r = scale(x, f->idx.xmin, f->idx.xmax, WIN_WIDTH);
	c.i = scale(y, f->idx.ymax, f->idx.ymin, WIN_HEIGHT);
	it = 0;
	while (it < f->max_it)
	{
		if (((z.r * z.r) + (z.i * z.i) > 4))
			break ;
		z = sum(z_square(z), c);
		it++;
	}
	return (it);
}
