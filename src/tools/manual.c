/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:40:44 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/08 22:38:03 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tutorial(void)
{
	ft_printf(BOLD FIRST_HEADER1 FIRST_HEADER2);
	ft_printf("|									    |\n");
	ft_printf("|				");
	rainbow_txt_nonl("   FRACT'OL   ");
	ft_printf("				    |\n");
	ft_printf("|									    |\n");
	ft_printf(BOLD FIRST_HEADER1 FIRST_HEADER2);
	ft_printf("\n" BOLD SEP HEADER SEP RESET"\n\n\n");
	ft_printf(BOLD BLUE "Available commands to use:\n" RESET);
	ft_printf("\n⭒ %s", BOLD "Arrows to move:" RESET);
	ft_printf("%s\n", "\t← ↑ → ↓  or  A W D S");
	ft_printf("⭒ %s", BOLD "Mouse wheel:" RESET);
	ft_printf("%s\n", "\t\tscroll up (zoom -)");
	ft_printf("%s\n\n", "\t\t\tscroll down (zoom +)");
	ft_printf("⭒ %s", BOLD "Keys to change color mode:" RESET);
	ft_printf("%s\n%s\n", "\tY: Default", "\t\t\t\tU: Lavender/Blue");
	ft_printf("%s\n", "\t\t\t\tI: Pink Psychedelic");
	ft_printf("%s\n", "\t\t\t\tO: Deep Pink Psychedelic");
	ft_printf("%s\n\n\n", "\t\t\t\tP: Yellow");
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
	ft_printf("%s\t\t%s\n", BOLD "Misshapen Bird", EXAMPLE(0.38, -0.12));
}

void	help_menu(void)
{
	ft_printf(BOLD SEP ARG_HEADER SEP RESET "\n\n\n");
	(ft_printf(BOLD BLUE INTRO1 RESET BOLD), rainbow_txt(INTRO2));
	ft_printf(BOLD PINK M_ARG1 RESET M_ARG2);
	ft_printf(BOLD PINK J_ARGS1 RESET J_ARGS2);
	ft_printf(BOLD PINK B_ARG1 RESET B_ARG2);
	ft_printf(BOLD PINK MX_ARG1 RESET MX_ARG2 "\n");
	ft_printf(BOLD SEP EX_HEADER SEP RESET "\n\n\n");
	ft_printf(ITAL YELLOW "(For Julia sets only)\n\n" RESET);
	julia_examples();
	ft_printf("\n");
}
