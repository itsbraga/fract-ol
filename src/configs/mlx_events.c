/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:02:44 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/02 15:50:00 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/*	
	Zooms the view of the fractal in or out by adjusting the complex
	number edge values by a zoom multiplier.
	The fractal is then generated again at a different resolution,
	giving the appearance of going further forwards or backwards.

	The smaller the zoom multiplier, the greater the zoom range (ex: 0.3)
	The greater the zoom multiplier, the further back the zoom will go (ex: 2.0)
*/
void	mouse_zoom(double zmult, t_fractol *f)
{
	t_complex	center;

	center.r = f->idx.xmin - f->idx.xmax;
	center.i = f->idx.ymax - f->idx.ymin;
	f->idx.xmax += (center.r - zmult * center.r) / 2;
	f->idx.xmin = f->idx.xmax + zmult * center.r;
	f->idx.ymin += (center.i - zmult * center.i) / 2;
	f->idx.ymax = f->idx.ymin + zmult * center.i;
}

static int	__mouse_hook(int button, int x, int y, t_fractol *f)
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
		return (EXIT_FAILURE);
	draw(f);
	return (EXIT_SUCCESS);
}

void	init_events(t_fractol *f)
{
	mlx_key_hook(f->win, key_hook, f);
	mlx_mouse_hook(f->win, __mouse_hook, f);
	mlx_hook(f->win, 17, (1L << 17), clean, f);
}
