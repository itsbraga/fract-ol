/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:02:44 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 16:49:00 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static int key_hook(int keycode, t_data *fractal)
{
    if (keycode == XK_Escape)
        clean(fractal);
    return (EXIT_SUCCESS);
}

static int mouse_hook(int mousecode, int x, int y, t_data *fractal)
{
    (void)x;
    (void)y;
    if (mousecode == MOUSE_WHEEL_UP)
    {
        ft_printf(BOLD BLUE "Scroll up (+):\tzoom\n" RESET);
        fractal->zoom -= 0.03;
    }
    else if (mousecode == MOUSE_WHEEL_DOWN)
    {
        ft_printf(BOLD PINK "Scroll down (-):\tunzoom\n" RESET);
        fractal->zoom += 0.03;
    }
    draw(fractal);
    return (EXIT_SUCCESS);
}

void	init_events(t_data *fractal)
{
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_hook(fractal->win, 4, (1L << 2), mouse_hook, fractal);
	mlx_hook(fractal->win, 17, (1L << 17), clean, fractal);
}
