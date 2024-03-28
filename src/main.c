/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:12:58 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 21:32:56 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void    errcontext_exit(void)
{
    perror("\nError");
    exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	f;
	
	if (argc != 2 || argc != 4)
	{
		ft_printf(BOLD RED "\nError: Invalid arguments.\n" RESET);
		(tutorial(), help_menu(), exit(EXIT_FAILURE));
	}
	memset4struct(&f, 0, sizeof(t_data));
	init_data(&f);
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		mandelbrot(argv, &f);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (!global_check_successful(argv))
			errcontext_exit();
		julia(argv, &f);
	}
	mlx_loop_hook(f.mlx, &draw, &f);
	(mlx_key_hook(f.win, &esc_key_hook, &f), mlx_key_hook(f.win, &keypress, &f));
	// mlx_mouse_hook(f.win, &mouse_hook, &f);
	// mlx_hook(f->win, 4, (1L << 2), &mouse_hook, f);
	mlx_hook(f.win, 17, (1L << 17), &clean, &f);
	mlx_loop(f.mlx);
}
