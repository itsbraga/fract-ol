/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:12:58 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/02 16:01:26 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	__clean_then_exit(t_fractol *f)
{
	clean(f);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2 && argc != 4)
	{
		ft_printf(BOLD RED "\nError: Invalid arguments.\n\n" RESET);
		(tutorial(), help_menu(), exit(EXIT_FAILURE));
	}
	ft_memset(&f, 0, sizeof(t_fractol));
	init_fractal(argv, &f);
	init_img(&f);
	if (argc == 4 && f.type == Julia)
	{
		if (check_julia_args(argv) == false)
			__clean_then_exit(&f);
		f.julia_c.r = atodbl(argv[2]);
		f.julia_c.i = atodbl(argv[3]);
	}
	mlx_loop_hook(f.mlx, &draw, &f);
	init_events(&f);
	mlx_loop(f.mlx);
}
