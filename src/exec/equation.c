/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:32:04 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/03 22:48:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum(t_complex z, t_complex c)
{
	t_complex	res;

	res.r = z.r + c.r;
	res.i = z.i + c.i;
	return (res);
}

t_complex	z_square(t_complex z)
{
	t_complex	res;

	res.r = (z.r * z.r);
	res.r -= (z.i * z.i);
	res.i = 2 * z.r * z.i;
	return (res);
}

/*	
	Scale takes a value n within a range of values defined by old_max,
 	then resizes it to fall within a new range of values defined by new_min
 	and new_max. This is useful for normalizing data or scaling values to fit
 	a certain interval.
*/
double	scale(double n, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * n / old_max + new_min);
}
