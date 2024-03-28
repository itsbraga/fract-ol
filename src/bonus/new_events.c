/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:50:40 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 21:32:29 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int keypress(int keycode, t_data *f)
{
	t_complex	c;

	c.r = f->idx.xmax - f->idx.xmin;
	c.i = f->idx.ymax - f->idx.ymin;
    if (keycode == XK_Left)
    {
        f->idx.xmax -= (c.r * 0.5);
		f->idx.xmin -= (c.r * 0.5);
    }
    else if (keycode == XK_Right)
    {
        f->idx.xmax += (c.r * 0.5);
		f->idx.xmin += (c.r * 0.5);
    }
    else if (keycode == XK_Up)
    {
		f->idx.ymax += (c.i * 0.5);
		f->idx.ymin += (c.i * 0.5);
    }
    else if (keycode == XK_Down)
    {
		f->idx.ymax -= (c.i * 0.5);
		f->idx.ymin -= (c.i * 0.5);
    }
    return (EXIT_SUCCESS);
}

void	keypress_msg(int keycode, t_data *f)
{
	if (keycode == XK_Left)
        ft_printf(BOLD PURPLE "Left key pressed:\tmoving ←\n" RESET);
    else if (keycode == XK_Right)
        ft_printf(BOLD YELLOW "Right key pressed:\tmoving →\n" RESET);
    else if (keycode == XK_Up)
        ft_printf(BOLD YELLOW "Up key pressed:\tmoving ↑\n" RESET);        
    else if (keycode == XK_Down)
        ft_printf(BOLD YELLOW "Down key pressed:\tmoving ↓\n" RESET);
}

static void	mouse_zoom(double m, t_data *f)
{
	t_complex	c;

	c.r = f->idx.xmin - f->idx.xmax;
	c.i = f->idx.ymax - f->idx.ymin;
	f->idx.xmax += (c.r - m * c.r) / 2;
	f->idx.xmin = f->idx.xmax + m * c.r;
	f->idx.ymin += (c.i - m * c.i) / 2;
	f->idx.ymax = f->idx.ymin + m * c.i;
}
