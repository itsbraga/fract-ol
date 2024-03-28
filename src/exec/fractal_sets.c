/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:05:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 18:13:56 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	view(t_view *v)
{
	v->x_min = -2.0;
	v->x_max = 2.0;
	v->y_min = -2.0;
	v->y_max = 2.0;
	v->zoom= 1.0;
}

void	set_pixels(t_data *fractal, double x, double y)
{
	int			it;
	t_complex	z;
	t_complex	c;
	
	it = 0;
	memset4struct(&z, 0, sizeof(t_complex));
	memset4struct(&c, 0, sizeof(t_complex));
	create_cplan(fractal, &z, &c, x, y);
	while (it < fractal->max_iter)
	{
		z = sum(z_square(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractal->esc_value)
		{
			put_pixels(&fractal->img, x, y, fractal->color + (0x38040E * it));
			return ;
		}
		it++;
	}
	put_pixels(&fractal->img, x, y, 0x000000);
}

void	draw(t_data *fractal)
{
	double x;
	double y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			set_pixels(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, 
		fractal->img.img_ptr, 0, 0);
}

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
	fractal->julia_r = atodbl(argv[2]);
	fractal->julia_i = atodbl(argv[3]);
	draw(fractal);
	mlx_loop(fractal->mlx);
}
