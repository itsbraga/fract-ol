/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:29:29 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 19:57:13 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    del_win(t_data *f)
{
    ft_printf(BOLD YELLOW "\nWindow successfully destroyed.\n\n" RESET);
    mlx_destroy_window(f->mlx, f->win);
	free(f->mlx);
    f->mlx = NULL;
    exit(EXIT_FAILURE);
}

void    del_img(t_data *f)
{
    ft_printf(BOLD YELLOW "\nImage and window successfully destroyed.\n\n");
    ft_printf(RESET);
    mlx_destroy_image(f->mlx, f->img.img_ptr);
    mlx_destroy_window(f->mlx, f->win);
	free(f->mlx);
    f->mlx = NULL;
	exit(EXIT_FAILURE);
}

int clean(t_data *f)
{
    ft_printf(BOLD YELLOW "\nExited the program cleanly.\n\n" RESET);
    mlx_destroy_image(f->mlx, f->img.img_ptr);
    mlx_destroy_window(f->mlx, f->win);
    mlx_destroy_display(f->mlx);
    free(f->mlx);
    f->mlx = NULL;
	exit(EXIT_SUCCESS);
}
