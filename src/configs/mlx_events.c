/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:02:44 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 21:16:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int esc_key_hook(int keycode, t_data *f)
{
    if (keycode == XK_Escape)
        clean(f);
    return (EXIT_SUCCESS);
}

int mouse_hook(int button, int x, int y, t_data *f)
{
    t_view  v;
    
    (void)x;
    (void)y;
    if (button == MOUSE_WHEEL_UP)
    {
        ft_printf(BOLD BLUE "Scroll up (+):\tzoom\n" RESET);
        v.zoom -= 0.03;
    }
    else if (button == MOUSE_WHEEL_DOWN)
    {
        ft_printf(BOLD PINK "Scroll down (-):\tunzoom\n" RESET);
        v.zoom += 0.03;
    }
    draw(f);
    return (EXIT_SUCCESS);
}

void	init_events(t_data *f)
{
	mlx_key_hook(f->win, esc_key_hook, f);
	mlx_hook(f->win, 4, (1L << 2), mouse_hook, f);
	mlx_hook(f->win, 17, (1L << 17), clean, f);
}
