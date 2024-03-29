/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:12:58 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/29 20:42:38 by annabrag         ###   ########.fr       */
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

	if (argc != 2 && argc != 4)
	{
		ft_printf(BOLD RED "\nError: Invalid arguments.\n" RESET);
		(tutorial(), help_menu(), exit(EXIT_FAILURE));
	}
	memset4struct(&f, 0, sizeof(t_data));
	init_data(&f);
	init_img(&f);
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (!global_check_successful(argv))
			errcontext_exit();
		f.name = argv[1];
		f.julia_c.r = atodbl(argv[2]);
		f.julia_c.i = atodbl(argv[3]);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		f.name = argv[1];
	mlx_loop_hook(f.mlx, &draw, &f);
	init_events(&f);
	mlx_loop(f.mlx);
}
