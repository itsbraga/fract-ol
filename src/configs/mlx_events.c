/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:02:44 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/30 00:28:26 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static int esc_key_hook(int keycode, t_data *f)
{
    if (keycode == XK_Escape)
        clean(f);
    return (EXIT_SUCCESS);
}

void	mouse_zoom(double zmult, t_data *f)
{
	t_complex	center;

	center.r = f->idx.xmin - f->idx.xmax;
	center.i = f->idx.ymax - f->idx.ymin;
	f->idx.xmax += (center.r - zmult * center.r) / 2;
	f->idx.xmin = f->idx.xmax + zmult * center.r;
	f->idx.ymin += (center.i - zmult * center.i) / 2;
	f->idx.ymax = f->idx.ymin + zmult * center.i;
}

static int	mouse_hook(int button, int x, int y, t_data *f)
{
	(void)x;
    (void)y;
	if (button == MOUSE_WHEEL_UP)
		mouse_zoom(0.8, f);
	else if (button == MOUSE_WHEEL_DOWN)
		mouse_zoom(1.7, f);
	draw(f);
	return (EXIT_SUCCESS);
}

void    init_events(t_data *f)
{
	mlx_key_hook(f->win, esc_key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, 17, (1L << 17), clean, f);
}
