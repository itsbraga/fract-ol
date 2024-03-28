/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:07:06 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 21:41:01 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	init_data(t_data *f)
{
	f->max_it = 100;
	f->color = 0;
	f->esc_value = 4;
}

void	view(t_view *v)
{
	v->xmin = -2.0;
	v->xmax = 2.0;
	v->ymin = -2.0;
	v->ymax = 2.0;
	v->zoom= 1.0;
}

void	init_img(t_data *f)
{
	t_img	img;
	char	*title;

	memset4struct(&img, 0, sizeof(t_img));
	title = ft_strjoin("Presenting\t\tAna's fract-ol: ", f->name);
	f->mlx = mlx_init();
	if (!f->mlx)
		(ft_printf(BOLD RED "MiniLibX: connection failed!\n"), exit(EXIT_FAILURE));
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, 
					title);
	if (!f->win)
		del_win(f);
	f->img.img_ptr = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!f->img.img_ptr)
		del_img(f);
	f->img.addr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
						&f->img.line_len, &f->img.endian);
	if (!f->img.addr)
	{
		ft_printf(BOLD RED "MiniLibX: failed at finding the image's address!\n");
		exit(EXIT_FAILURE);
	}
}
