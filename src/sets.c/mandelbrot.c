/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:36:46 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 21:18:30 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/*	Its point of interest is c, and z = 0	*/
int	mandelbrot(char **argv, t_data *f, t_complex c)
{
	int			it;
	t_complex	z;

	memset4struct(&z, 0, sizeof(t_complex));
	memset4struct(&c, 0, sizeof(t_complex));
	it = 0;
	f->name = argv[1];
	while (it < f->max_it)
	{
		z = sum(z_square(z), c);
		if (((z.r * z.r) + (z.i * z.i) > f->esc_value))
			break ;
		it++;
	}
	return (it);
}
