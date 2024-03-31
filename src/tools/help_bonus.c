/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:40:44 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/31 22:46:00 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	julia_examples_bonus(void)
{
	ft_printf(BOLD "Elephant Valley" RESET);
	ft_printf("\t\t-->\t./fractol_bonus julia 0.3 0.0\n");
	ft_printf(BOLD "Sea Horse Valley" RESET);
	ft_printf("\t-->\t./fractol_bonus julia -0.75 0.1\n");
	ft_printf(BOLD "Mystic Dragon" RESET);
	ft_printf("\t\t-->\t./fractol_bonus julia -0.8 0.156\n");
	ft_printf(BOLD "Winter Season" RESET);
	ft_printf("\t\t-->\t./fractol_bonus julia -0.4 0.6\n");
	ft_printf(BOLD "Spirals" RESET);
	ft_printf("\t\t\t-->\t./fractol_bonus julia 0.355 0.355\n");
	ft_printf(BOLD "Frozen Spirals" RESET);
	ft_printf("\t\t-->\t./fractol_bonus julia -0.54 0.54\n");
	ft_printf(BOLD "BPM" RESET);
	ft_printf("\t\t\t-->\t./fractol_bonus julia -1.476 0.0\n");
	ft_printf(BOLD "Flowers" RESET);
	ft_printf("\t\t\t-->\t./fractol_bonus julia -0.52 0.57\n");
	ft_printf(BOLD "Multiverse" RESET);
	ft_printf("\t\t-->\t./fractol_bonus julia 0.285 0.013\n");
	ft_printf(BOLD "Misshapen Bird" RESET);
	ft_printf("\t\t-->\t./fractol_bonus julia 0.38 -0.12\n");
}

void	help_menu_bonus(void)
{
	ft_printf(BOLD SEP ARG_HEADER SEP RESET "\n\n\n");
	(ft_printf(BOLD BLUE INTRO1 RESET BOLD), rainbow_txt(INTRO2));
	ft_printf(BOLD PINK M_ARG1 RESET B_M_ARG2);
	ft_printf(BOLD PINK J_ARGS1 RESET B_J_ARGS2);
	ft_printf(BOLD PINK B_ARG1 RESET B_B_ARG2);
	ft_printf(BOLD PINK MX_ARG1 RESET B_MX_ARG2 "\n");
	ft_printf(BOLD SEP EX_HEADER SEP RESET "\n\n\n");
	ft_printf(ITAL YELLOW "(For Julia sets only)\n\n" RESET);
	julia_examples_bonus();
	ft_printf("\n");
}
