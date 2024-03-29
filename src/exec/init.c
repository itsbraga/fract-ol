/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:07:06 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/29 21:44:12 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	init_data(t_data *f)
{
	f->max_it = 200;
	f->color = DEFAULT;
	f->esc_value = 4;
	f->idx.xmin = -2.0;
	f->idx.xmax = 2.0;
	f->idx.ymin = -2.0;
	f->idx.ymax = 2.0;
}

void	init_img(t_data *f)
{
	t_img	img;
	char	*title;

	title = ft_strjoin("Presenting\t\tAna's fract-ol: ", f->name);
	memset4struct(&img, 0, sizeof(t_img));
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		ft_printf(BOLD RED "MiniLibX: connection failed!\n");
		exit(EXIT_FAILURE);
	}
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, title);
	if (!f->win)
		del_win(f);
	f->img.img_ptr = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!f->img.img_ptr)
		del_img(f);
	f->img.addr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
						&f->img.line_len, &f->img.endian);
	if (!f->img.addr)
	{
		ft_printf(BOLD RED"MiniLibX: failed at finding the image's address!\n");
		exit(EXIT_FAILURE);
	}
}
