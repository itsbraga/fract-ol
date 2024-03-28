/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:07:06 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 17:44:21 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	init_data(t_data *fractal)
{
	fractal->max_iter = 100;
	fractal->zoom = 1.0;
	fractal->color = 0;
}

void	init_fractal(t_data *fractal)
{
	t_img	img;
	char	*title;

	title = ft_strjoin("Presenting Ana's fract-ol: ", fractal->name);
	memset4struct(&img, 0, sizeof(t_img));
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		(ft_printf(BOLD RED "MiniLibX connection failed!\n"), exit(EXIT_FAILURE));
	fractal->win = mlx_new_window(fractal->mlx, WIN_WIDTH, WIN_HEIGHT, 
					title);
	if (!fractal->win)
		del_win(fractal);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fractal->img.img_ptr)
		del_img(fractal);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr,
						&fractal->img.bpp,
						&fractal->img.line_len,
						&fractal->img.endian);
	init_data(fractal);
	init_events(fractal);
}

void	draw(t_data *fractal)
{
	int	x;
	int	y;

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
