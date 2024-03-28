/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:38:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/03/28 19:57:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	*memset4struct(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*f;

	i = 0;
	f = s;
	while (i < n)
	{
		*(f + i) = c;
		i++;
	}
	return (f);
}

void	rainbow_txt(const char *str)
{
	const char *colors[7] = {RED, YELLOW, GREEN, CYAN, BLUE, PURPLE, PINK};
	size_t		nb_colors;
	size_t		idx_color;
	size_t		i;

	nb_colors = sizeof(colors) / sizeof(colors[0]);
	idx_color = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		ft_printf("%s%c", colors[idx_color], str[i]);
		idx_color = (idx_color + 1) % nb_colors;
		i++;
	}
	ft_printf("%s\n", RESET);
}
