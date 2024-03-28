/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:29:29 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 16:25:08 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    del_win(t_data *fractal)
{
    ft_printf(BOLD YELLOW "\nWindow successfully destroyed.\n\n" RESET);
    mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal->mlx);
    fractal->mlx = NULL;
    exit(EXIT_FAILURE);
}

void    del_img(t_data *fractal)
{
    ft_printf(BOLD YELLOW "\nImage and window successfully destroyed.\n\n");
    ft_printf(RESET);
    mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal->mlx);
    fractal->mlx = NULL;
	exit(EXIT_FAILURE);
}

int clean(t_data *fractal)
{
    ft_printf(BOLD YELLOW "\nExited the program cleanly.\n\n" RESET);
    mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx, fractal->win);
    mlx_destroy_display(fractal->mlx);
    free(fractal->mlx);
    fractal->mlx = NULL;
	exit(EXIT_SUCCESS);
}
