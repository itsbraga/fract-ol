/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 18:12:09 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    put_pixels(t_img *img, int x, int y, int color)
{
	char	*buffer;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	buffer = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)buffer = color;
}

// changer map pour view avec x & y + retirer x & y des params
static void	create_cplan(t_data *fractal, t_complex *z, t_complex *c, double x, double y)
{
	t_view	v;
	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		z->r = map(x, -2, 2, WIN_WIDTH) * v.zoom;
		z->i = map(y, 2, -2, WIN_HEIGHT) * v.zoom;
		c->r = fractal->julia_r;
		c->i = fractal->julia_i;
	}
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		z->r = 0.0;
		z->i = 0.0;
		c->r = map(x, -2, 2, WIN_WIDTH) * v.zoom;
		c->i = map(y, 2, -2, WIN_HEIGHT) * v.zoom;
	}
}
