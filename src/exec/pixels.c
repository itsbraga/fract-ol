/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/30 00:53:59 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*buffer;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	buffer = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)buffer = color;
}

static int	choice(t_data *f, int x, int y)
{
	int	it;

	it = 0;
	if (!ft_strncmp(f->name, "mandelbrot", 10))
		it = mandelbrot(f, x, y);
	else if (!ft_strncmp(f->name, "julia", 5))
		it = julia(f, x, y);
	return (it);
}

int	draw(t_data *f)
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
			it = choice(f, x, y);
			if (it == f->max_it)
				my_mlx_pixel_put(&f->img, x, y, 0x000000);
			else
				my_mlx_pixel_put(&f->img, x, y, (f->color * it));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}
