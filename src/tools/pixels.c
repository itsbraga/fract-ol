/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 21:39:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*buffer;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	buffer = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)buffer = color;
}

// changer scale pour view avec x & y + retirer x & y des params
static void	create_cplan(t_data *f, t_complex *z, t_complex *c, double x, double y)
{
	t_view	v;
	
	if (!ft_strncmp(f->name, "julia", 5))
	{
		z->r = scale(x, f->idx.xmin, f->idx.xmax, WIN_WIDTH) * v.zoom;
		z->i = scale(y, f->idx.ymax, f->idx.ymin, WIN_HEIGHT) * v.zoom;
		c->r = f->julia_c.r;
		c->i = f->julia_c.i;
	}
	else if (!ft_strncmp(f->name, "mandelbrot", 10))
	{
		z->r = 0.0;
		z->i = 0.0;
		c->r = scale(x, f->idx.xmin, f->idx.xmax, WIN_WIDTH) * v.zoom;
		c->i = scale(y, f->idx.ymax, f->idx.ymin, WIN_HEIGHT) * v.zoom;
	}
}

void	draw(t_data *f)
{
	int	it;
	int	x;
	int	y;

	it = 0;
	y = 0;
	// mlx_clear_window(f->mlx, f->win);
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(&f->img, x, y, f->color + (0x38040E * it));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}
