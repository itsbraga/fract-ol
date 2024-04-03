/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/03 22:48:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	__my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*buffer;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	buffer = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)buffer = color;
}

/*
	Picks the correct fractal calculation function depending
	on the choosen fractal set.
*/
static int	__choice(t_fractol *f, int x, int y)
{
	int	it;

	it = 0;
	if (f->type == Mandelbrot)
		it = mandelbrot(f, x, y);
	else if (f->type == Julia)
		it = julia(f, x, y);
	else if (f->type == Burningship)
		it = burningship(f, x, y);
	else if (f->type == Mandelbox)
		it = mandelbox(f, x, y);
	return (it);
}

int	draw(t_fractol *f)
{
	int	it;
	int	x;
	int	y;

	it = 0;
	y = 0;
	mlx_clear_window(f->mlx, f->win);
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			it = __choice(f, x, y);
			if (it == f->max_it)
				__my_mlx_pixel_put(&f->img, x, y, 0x000000);
			else
				__my_mlx_pixel_put(&f->img, x, y, (f->color * it));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}
