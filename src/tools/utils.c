/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:38:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/03 22:48:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rainbow_txt(const char *str)
{
	const char	*colors[7] = {RED, YELLOW, GREEN, CYAN, BLUE, PURPLE, PINK};
	size_t		nb_colors;
	size_t		i;
	size_t		len;

	nb_colors = sizeof(colors) / sizeof(colors[0]);
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		ft_printf("%s%c", colors[i % nb_colors], str[i]);
		i++;
	}
	ft_printf("%s\n", RESET);
}

void	rainbow_txt_nonl(const char *str)
{
	const char	*colors[7] = {RED, YELLOW, GREEN, CYAN, BLUE, PURPLE, PINK};
	size_t		nb_colors;
	size_t		i;
	size_t		len;

	nb_colors = sizeof(colors) / sizeof(colors[0]);
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		ft_printf("%s%c", colors[i % nb_colors], str[i]);
		i++;
	}
	ft_printf(RESET);
}
