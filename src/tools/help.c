/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:39:10 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/31 22:48:20 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

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
	ft_printf(BOLD "Elephant Valley" RESET);
	ft_printf("\t\t-->\t./fractol julia 0.3 0.0\n");
	ft_printf(BOLD "Sea Horse Valley" RESET);
	ft_printf("\t-->\t./fractol julia -0.75 0.1\n");
	ft_printf(BOLD "Mystic Dragon" RESET);
	ft_printf("\t\t-->\t./fractol julia -0.8 0.156\n");
	ft_printf(BOLD "Winter Season" RESET);
	ft_printf("\t\t-->\t./fractol julia -0.4 0.6\n");
	ft_printf(BOLD "Spirals" RESET);
	ft_printf("\t\t\t-->\t./fractol julia 0.355 0.355\n");
	ft_printf(BOLD "Frozen Spirals" RESET);
	ft_printf("\t\t-->\t./fractol julia -0.54 0.54\n");
	ft_printf(BOLD "BPM" RESET);
	ft_printf("\t\t\t-->\t./fractol julia -1.476 0.0\n");
	ft_printf(BOLD "Flowers" RESET);
	ft_printf("\t\t\t-->\t./fractol julia -0.52 0.57\n");
	ft_printf(BOLD "Multiverse" RESET);
	ft_printf("\t\t-->\t./fractol julia 0.285 0.013\n");
	ft_printf(BOLD "Misshapen Bird" RESET);
	ft_printf("\t\t-->\t./fractol julia 0.38 -0.12\n");
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
