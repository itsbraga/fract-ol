/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:07:06 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/30 18:36:07 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	init_fractal(char **argv, t_fractal *f)
{
	f->max_it = 200;
	f->color = DEFAULT;
	f->esc_value = 4;
	f->idx.xmin = -2.0;
	f->idx.xmax = 2.0;
	f->idx.ymin = -2.0;
	f->idx.ymax = 2.0;
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		f->type = Mandelbrot;
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		f->type = Julia;
	else
	{
		ft_printf(BOLD RED "\nError: Invalid fractal name.\n\n" RESET);
		exit(EXIT_FAILURE);
	}
}

void	init_img(t_fractal *f)
{
	t_img	img;
	char	*title;

	ft_memset(&img, 0, sizeof(t_img));
	title = ft_strdup("Presenting:\tAna's fract-ol");
	f->mlx = mlx_init();
	if (f->mlx == NULL)
	{
		ft_printf(BOLD RED "MiniLibX: connection failed!\n");
		exit(EXIT_FAILURE);
	}
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, title);
	if (f->win == NULL)
		del_win(f);
	free(title);
	f->img.img_ptr = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (f->img.img_ptr == NULL)
		del_img(f);
	f->img.addr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	if (f->img.addr == NULL)
	{
		ft_printf(BOLD RED"MiniLibX: failed at finding the image's address!\n");
		exit(EXIT_FAILURE);
	}
}
