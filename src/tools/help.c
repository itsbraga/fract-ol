/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:39:10 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/30 18:59:46 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	tutorial(void)
{
	ft_printf("\n" BOLD SEP HEADER SEP RESET"\n\n\n");
	ft_printf(BOLD BLUE "Available commands to use:\n\n" RESET);
	ft_printf("\n⭒ %s\n", "Arrows to move:\t↑ ↓ ← →");
	ft_printf("⭒ %s\n", "Mouse wheel:\t\tscroll up (zoom -)");
	ft_printf("%s\n\n\n\n", "\t\t\tscroll down (zoom +)");
}

void	julia_examples(void)
{
	ft_printf(BOLD "Elephant Valley");
	ft_printf(RESET "\t\t-->\t./fractol julia 0.3 0.0\n");
	ft_printf(BOLD "Sea Horse Valley");
	ft_printf(RESET "\t\t-->\t./fractol julia -0.75 0.1\n");
	ft_printf(BOLD "Mystic Dragon");
	ft_printf(RESET "\t\t-->\t./fractol julia -0.8 0.156\n");
	ft_printf(BOLD "Winter Season");
	ft_printf(RESET "\t\t-->\t./fractol julia -0.4 0.6\n");
	ft_printf(BOLD "Spirals");
	ft_printf(RESET "\t\t-->\t./fractol julia 0.355 0.355\n");
	ft_printf(BOLD "Frozen Spirals");
	ft_printf(RESET "\t\t-->\t./fractol julia -0.54 0.54\n");
	ft_printf(BOLD "BPM");
	ft_printf(RESET "\t\t-->\t./fractol julia -1.476 0.0\n");
	ft_printf(BOLD "Flowers");
	ft_printf(RESET "\t\t-->\t./fractol julia -0.52 0.57\n");
	ft_printf(BOLD "Multiverse");
	ft_printf(RESET "\t\t-->\t./fractol julia 0.285 0.013\n");
	ft_printf(BOLD "Misshapen Bird");
	ft_printf(RESET "\t\t-->\t./fractol julia 0.38 -0.12\n");
}

void	help_menu(void)
{
	ft_printf(BOLD SEP ARG_HEADER SEP RESET "\n\n\n");
	(ft_printf(BOLD BLUE INTRO1 RESET BOLD), rainbow_txt(INTRO2));
	ft_printf(BOLD M_ARG1 RESET M_ARG2 BOLD J_ARGS1 RESET J_ARGS2 "\n\n");
	ft_printf(BOLD SEP EX_HEADER SEP RESET "\n\n\n");
	ft_printf(ITAL YELLOW "(For Julia sets only)\n\n\n" RESET);
	(julia_examples(), ft_printf("\n"));
}
