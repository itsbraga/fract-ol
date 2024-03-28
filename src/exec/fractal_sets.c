/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:05:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 17:51:08 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	mandelbrot(char **argv, t_data *fractal)
{
	t_complex	z;
	t_complex	c;

	memset4struct(&z, 0, sizeof(t_complex));
	memset4struct(&c, 0, sizeof(t_complex));
	fractal->name = argv[1];
	init_fractal(fractal);
	draw(fractal);
	mlx_loop(fractal->mlx);
}

void	julia(char **argv, t_data *fractal)
{
	t_complex	z;
	t_complex	c;

	memset4struct(&z, 0, sizeof(t_complex));
	memset4struct(&c, 0, sizeof(t_complex));	
	fractal->name = argv[1];
	init_fractal(fractal);
	fractal->julia_r = atod(argv[2]);
	fractal->julia_i = atod(argv[3]);
	draw(fractal);
	mlx_loop(fractal->mlx);
}
