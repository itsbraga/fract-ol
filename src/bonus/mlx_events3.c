/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:00:21 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/30 00:29:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static int	mouse_hook2(int button, int x, int y, t_data *f)
{
	if (button == MOUSE_WHEEL_UP)
	{
		mouse_zoom(0.5, f);
		y -= WIN_HEIGHT / 2;
		x -= WIN_WIDTH / 2;
		ft_printf("x = %d\n", x);
		ft_printf("y = %d\n", y);
		if (y < 0)
			key_move(XK_Up, (double)y * -1 / WIN_HEIGHT, f);
		else if (y > 0)
			key_move(XK_Down, (double)y / WIN_HEIGHT, f);
		if (x < 0)
			key_move(XK_Left, (double)x * -1 / WIN_WIDTH, f);
		else if (x > 0)
			key_move(XK_Right, (double)x / WIN_WIDTH, f);
	}
	else if (button == MOUSE_WHEEL_DOWN)
		mouse_zoom(1.7, f);
	else
	{
		ft_printf(BOLD RED "\nSorry buddy, this move is not supported!\n");
		return (EXIT_FAILURE);
	}
	draw(f);
	return (EXIT_SUCCESS);
}

void    init_events2(t_data *f)
{
	init_events(f);
	mlx_key_hook(f->win, key_hook2, f);
	mlx_mouse_hook(f->win, mouse_hook2, f);
}
