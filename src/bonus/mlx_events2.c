/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:50:40 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/30 20:01:24 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	key_msg(int keycode)
{
	if (keycode == XK_Up)
		ft_printf(BOLD GREEN "Up key pressed:\t\tmoving ↑\n" RESET);
	else if (keycode == XK_Down)
		ft_printf(BOLD BLUE "Down key pressed:\tmoving ↓\n" RESET);
	else if (keycode == XK_Left)
		ft_printf(BOLD YELLOW "Left key pressed:\tmoving ←\n" RESET);
	else if (keycode == XK_Right)
		ft_printf(BOLD ORANGE "Right key pressed:\tmoving →\n" RESET);
	else if (keycode == ZERO)
		ft_printf(BOLD "Changing color mode to:\tDEFAULT\n" RESET);
	else if (keycode == ONE)
		ft_printf(BOLD "Changing color mode to:\tx\n" RESET);
	else if (keycode == TWO)
		ft_printf(BOLD "Changing color mode to:\tPINK_PSYCHE\n" RESET);
	else if (keycode == THREE)
		ft_printf(BOLD "Changing color mode to:\tDEEP_PINK_PSYCHE\n" RESET);
}

void	key_move(int keycode, double dist, t_fractal *f)
{
	t_complex	c;

	c.r = f->idx.xmax - f->idx.xmin;
	c.i = f->idx.ymax - f->idx.ymin;
	if (keycode == XK_Up)
	{
		f->idx.ymax += (c.i * dist);
		f->idx.ymin += (c.i * dist);
	}
	else if (keycode == XK_Down)
	{
		f->idx.ymax -= (c.i * dist);
		f->idx.ymin -= (c.i * dist);
	}
	else if (keycode == XK_Left)
	{
		f->idx.xmax -= (c.r * dist);
		f->idx.xmin -= (c.r * dist);
	}
	else if (keycode == XK_Right)
	{
		f->idx.xmax += (c.r * dist);
		f->idx.xmin += (c.r * dist);
	}
	key_msg(keycode);
}

int	key_hook2(int keycode, t_fractal *f)
{
	if (keycode == XK_Up)
		key_move(XK_Up, 0.1, f);
	else if (keycode == XK_Down)
		key_move(XK_Down, 0.1, f);
	else if (keycode == XK_Left)
		key_move(XK_Left, 0.1, f);
	else if (keycode == XK_Right)
		key_move(XK_Right, 0.1, f);
	else if (keycode == ZERO)
		f->color = DEFAULT;
	else if (keycode == ONE)
		f->color = LIGHT_SEA_GREEN;
	else if (keycode == TWO)
		f->color = PINK_PSYCHE;
	else if (keycode == THREE)
		f->color = DEEP_PINK_PSYCHE;
	key_msg(keycode);
	draw(f);
	return (EXIT_SUCCESS);
}
