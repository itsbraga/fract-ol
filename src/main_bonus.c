/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:20:09 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/31 23:13:32 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	__errcontext_exit(t_fractol *f)
{
	perror("\nError");
	clean(f);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2 && argc != 4)
	{
		ft_printf(BOLD RED "\nError: Invalid arguments.\n\n" RESET);
		(tutorial(), help_menu_bonus(), exit(EXIT_FAILURE));
	}
	ft_memset(&f, 0, sizeof(t_fractol));
	init_fractal(argv, &f);
	init_img(&f);
	if (argc == 4 && f.type == Julia)
	{
		if (check_julia_args(argv) == false)
			__errcontext_exit(&f);
		f.julia_c.r = atodbl(argv[2]);
		f.julia_c.i = atodbl(argv[3]);
	}
	mlx_loop_hook(f.mlx, &draw, &f);
	init_events2(&f);
	mlx_loop(f.mlx);
}
