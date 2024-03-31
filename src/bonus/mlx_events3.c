/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:00:21 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/31 22:34:10 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static int	__mouse_hook2(int button, int x, int y, t_fractol *f)
{
	if (button == MOUSE_WHEEL_UP)
	{
		ft_printf(BOLD MUP_MSG RESET);
		mouse_zoom(0.5, f);
		y -= WIN_HEIGHT / 2;
		x -= WIN_WIDTH / 2;
		if (y < 0)
			key_move(XK_Down, (double)y * -1 / WIN_HEIGHT, f);
		else if (y > 0)
			key_move(XK_Up, (double)y / WIN_HEIGHT, f);
		if (x < 0)
			key_move(XK_Right, (double)x * -1 / WIN_WIDTH, f);
		else if (x > 0)
			key_move(XK_Left, (double)x / WIN_WIDTH, f);
	}
	else if (button == MOUSE_WHEEL_DOWN)
		(mouse_zoom(1.7, f), ft_printf(BOLD MDOWN_MSG RESET));
	else
	{
		ft_printf(BOLD RED "\nSorry buddy, this move is not supported!\n");
		ft_printf(RESET);
		return (EXIT_FAILURE);
	}
	draw(f);
	return (EXIT_SUCCESS);
}

void	init_events2(t_fractol *f)
{
	mlx_key_hook(f->win, key_hook2, f);
	mlx_mouse_hook(f->win, __mouse_hook2, f);
	mlx_hook(f->win, 17, (1L << 17), clean, f);
}
