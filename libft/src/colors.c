/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:14:36 by art3mis           #+#    #+#             */
/*   Updated: 2024/03/31 22:25:21 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/libft.h"
// #include "../include/ft_printf.h"

// #define COLOR_NB 6
// #define COLORS {31, 32, 33, 34, 35, 36}

// int	rand_color(void)
// {
// 	static int	colors[] = COLORS;

// 	return (colors[rand() % COLOR_NB]);
// }

// void	colorize_char(char c)
// {
// 	int	color;

// 	color = rand_color();
// 	ft_printf("\033[%dm%c\033[0m", color, c);
// }

// void	colorize_in_allcolors(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < strlen(str))
// 	{
// 		colorize_char(str[i]);
// 		++i;
// 	}
// 	ft_printf("\n");
// }

// int	main()
// {
// 	srand(time(NULL));
// 	colorize_in_allcolors("Available commands to use:\n");
// 	return (0);
// }
