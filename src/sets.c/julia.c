/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:35:54 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 21:24:25 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/*	Its point of interest is z, and c is a constant	*/
int	julia(char **argv, t_data *f, t_complex z)
{
	int			it;
	t_complex	c;

	memset4struct(&z, 0, sizeof(t_complex));
	memset4struct(&c, 0, sizeof(t_complex));
	it = 0;
	f->julia_c.r = atodbl(argv[2]);
	f->julia_c.i = atodbl(argv[3]);
	c.r = f->julia_c.r;
	c.i = f->julia_c.i;
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
