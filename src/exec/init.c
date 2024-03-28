/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:07:06 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 18:10:47 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	init_data(t_data *fractal)
{
	fractal->max_iter = 100;
	fractal->color = 0;
	fractal->esc_value = 4;
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
