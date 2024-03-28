/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:39:10 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 14:23:06 by annabrag         ###   ########.fr       */
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
	ft_printf("%s\t\t%s\n", BOLD "Elephant Valley", EXAMPLE(0.3, 0.0));
	ft_printf("%s\t%s\n", BOLD "Sea Horse Valley", EXAMPLE(-0.75, 0.1));
	ft_printf("%s\t\t%s\n", BOLD "Mystic Dragon", EXAMPLE(-0.8, 0.156));
	ft_printf("%s\t\t%s\n", BOLD "Winter Season", EXAMPLE(-0.4, 0.6));
	ft_printf("%s\t\t\t%s\n", BOLD "Spirals", EXAMPLE(0.355, 0.355));
	ft_printf("%s\t\t%s\n", BOLD "Frozen Spirals", EXAMPLE(-0.54, 0.54));
	ft_printf("%s\t\t\t%s\n", BOLD "BPM", EXAMPLE(-1.476, 0.0));
	ft_printf("%s\t\t\t%s\n", BOLD "Flowers", EXAMPLE(-0.52, 0.57));
	ft_printf("%s\t\t%s\n", BOLD "Multiverse", EXAMPLE(0.285, 0.013));
	ft_printf("%s\t\t%s\n\n", BOLD "Misshapen Bird", EXAMPLE(0.38, -0.12));
}

void	help_menu(void)
{
	ft_printf(BOLD SEP ARG_HEADER SEP RESET "\n\n\n");
	(ft_printf(BOLD BLUE INTRO1 RESET BOLD), rainbow_txt(INTRO2));
	ft_printf(RESET M_ARG1 M_ARG2 J_ARGS1 J_ARGS2 "\n\n");
	ft_printf(BOLD SEP EX_HEADER SEP RESET "\n\n\n");
	ft_printf(ITAL YELLOW "(For Julia sets only)\n\n\n" RESET);
	(julia_examples(), ft_printf("\n"));
}
