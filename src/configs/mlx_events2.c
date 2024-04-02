/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:50:40 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/02 15:48:21 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	__key_msg(int keycode)
{
	if (keycode == XK_Up || keycode == W)
		ft_printf(BOLD "UP Key:\t\tmoving ↑\n" RESET);
	else if (keycode == XK_Down || keycode == S)
		ft_printf(BOLD "DOWN Key:\tmoving ↓\n" RESET);
	else if (keycode == XK_Left || keycode == A)
		ft_printf(BOLD "LEFT Key:\tmoving ←\n" RESET);
	else if (keycode == XK_Right || keycode == D)
		ft_printf(BOLD "RIGHT Key:\tmoving →\n" RESET);
	else if (keycode == Y)
		ft_printf(BOLD ITAL ORANGE "New color mode:\tDEFAULT\n" RESET);
	else if (keycode == U)
		ft_printf(BOLD ITAL BLUE "New color mode:\tLAVENDER\n" RESET);
	else if (keycode == I)
		ft_printf(BOLD ITAL PINK "New color mode:\tPINK_PSYCHE\n" RESET);
	else if (keycode == O)
		ft_printf(BOLD ITAL PURPLE "New color mode:\tDEEP_PINK_PSYCHE\n" RESET);
	else if (keycode == P)
		ft_printf(BOLD ITAL YELLOW "New color mode:\tCANARY\n" RESET);
}

/*	
	Moves the view of the fractal by adjusting the complex number
	edge values a certain distance in a certain direction given by
	the choosen key	(keycode).
*/
void	key_move(int keycode, double dist, t_fractol *f)
{
	t_complex	center;

	center.r = f->idx.xmax - f->idx.xmin;
	center.i = f->idx.ymax - f->idx.ymin;
	if (keycode == XK_Up)
	{
		f->idx.ymax += (center.i * dist);
		f->idx.ymin += (center.i * dist);
	}
	else if (keycode == XK_Down)
	{
		f->idx.ymax -= (center.i * dist);
		f->idx.ymin -= (center.i * dist);
	}
	else if (keycode == XK_Left)
	{
		f->idx.xmax += (center.r * dist);
		f->idx.xmin += (center.r * dist);
	}
	else if (keycode == XK_Right)
	{
		f->idx.xmax -= (center.r * dist);
		f->idx.xmin -= (center.r * dist);
	}
}

// printf("keycode: %d\n", keycode);
int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == XK_Escape)
		clean(f);
	if (keycode == XK_Up || keycode == W)
		key_move(XK_Up, 0.1, f);
	else if (keycode == XK_Down || keycode == S)
		key_move(XK_Down, 0.1, f);
	else if (keycode == XK_Left || keycode == A)
		key_move(XK_Left, 0.1, f);
	else if (keycode == XK_Right || keycode == D)
		key_move(XK_Right, 0.1, f);
	else if (keycode == Y)
		f->color = DEFAULT;
	else if (keycode == U)
		f->color = LAVENDER;
	else if (keycode == I)
		f->color = PINK_PSYCHE;
	else if (keycode == O)
		f->color = DEEP_PINK_PSYCHE;
	else if (keycode == P)
		f->color = CANARY;
	__key_msg(keycode);
	draw(f);
	return (EXIT_SUCCESS);
}
