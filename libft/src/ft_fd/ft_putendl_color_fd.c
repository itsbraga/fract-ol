/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:38:33 by art3mis           #+#    #+#             */
/*   Updated: 2024/03/31 22:20:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putendl_color_fd(char *color, char *s, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putendl_fd(s, fd);
	ft_putstr_fd(RESET, fd);
}
