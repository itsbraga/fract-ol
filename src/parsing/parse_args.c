/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:13:58 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 18:15:08 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static double	atodbl_part2(char *s, int i)
{
	double	decimal;
	double	divisor;

	decimal = 0;
	divisor = 1;
	while (s[i] && (s[i] >= 48 && s[i] <= 57))
	{
		divisor /= 10;
		decimal = decimal + (s[i] - 48) * divisor;
		i++;
	}
	return (decimal);
}

double	atodbl(char *s)
{
	int		i;
	int		sign;
	double	int_part;
	double	decimal;

	i = 0;
	sign = 1;
	int_part = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
			sign *= -1;
	while (s[i] && (s[i] >= 48 && s[i] <= 57))
	{
		int_part = int_part * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] == '.' || s[i] == ',')
		i++;
	decimal = atodbl_part2(s, i);
	return (sign * (int_part + decimal));
}
