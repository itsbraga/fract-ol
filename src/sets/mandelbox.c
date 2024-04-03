/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:37:07 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/03 22:48:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ball_fold(double magnitude, double radius)
{
	if (magnitude < radius)
		magnitude = magnitude / (radius * radius);
	else if (magnitude < 1)
		magnitude = 1 / (magnitude * magnitude);
	return (magnitude);
}

static double	box_fold(double view)
{
	if (view > 1)
		view = 2 - view;
	else if (view < -1)
		view = -2 - view;
	return (view);
}

/*
	The Mandelbox set is a variation of the Mandelbrot fractal.

	Like the Mandelbrot set, it is calculated by applying a formula
	repeatedly to every point in space.
	
	Mandelbrot equation:
		z = z * z + c
	
	Mandelbox equation:
		v = s * ball_fold(r, f * box_fold(v)) + c

	- v: starting complex number (the translated pixel coordinates)
	- c: unscaled complex number (pixel coordinates)
	- s: scale multiplier
	- r: minimum radius
	- f: fixed radius

	4 = hypothenuse, escape value
*/
int	mandelbox(t_fractol *f, int x, int y)
{
	int			it;
	double		magnitude;
	t_complex	view;
	t_complex	c;

	ft_memset(&view, 0, sizeof(t_complex));
	ft_memset(&c, 0, sizeof(t_complex));
	view.r = c.r;
	view.i = c.i;
	c.r = scale(x, f->idx.xmin, f->idx.xmax, WIN_WIDTH);
	c.i = scale(y, f->idx.ymax, f->idx.ymin, WIN_HEIGHT);
	it = 0;
	magnitude = 0;
	while (it < f->max_it)
	{
		view.r = 1 * box_fold(view.r);
		view.i = 1 * box_fold(view.i);
		magnitude = sqrt((view.r * view.r) + (view.i * view.i));
		view.r = view.r * 2 * ball_fold(magnitude, 0.5) + c.r;
		view.i = view.i * 2 * ball_fold(magnitude, 0.5) + c.i;
		if (sqrt(magnitude) > 2)
			break ;
		it++;
	}
	return (it);
}
