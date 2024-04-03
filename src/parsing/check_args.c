/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:28 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/03 22:48:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	__is_only_double(char *argv)
{
	int		i;
	bool	has_decimal;

	i = 0;
	has_decimal = false;
	if (argv[0] == 0 || argv[0] == '.' || argv[0] == ',')
		return (false);
	else if (ft_isdigit(argv[i]) == false && ft_isdigit(argv[i + 1]) == false)
		return (false);
	if (argv[i] == '-' && argv[i + 1])
		i++;
	while (argv[i] && (ft_isdigit(argv[i]) || argv[i] == '.' || argv[i] == ','))
	{
		if (argv[i] == '.' || argv[i] == ',')
		{
			if (has_decimal == true)
				return (false);
			else
				has_decimal = true;
		}
		i++;
	}
	return (true);
}

static bool	__have_duplicate(char *argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (argv[j] == argv[i] && (argv[i] < 48 || argv[i] > 57))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

// const char	*mandatory = {"./fractol"};
// const char	*bonus = {"./fractol_bonus"};
bool	check_julia_args(char **argv)
{
	if (__is_only_double(argv[2]) == false
		|| __is_only_double(argv[3]) == false)
	{
		perror("\nError, invalid arguments");
		write(1, ITAL ORANGE EXAMPLE_MSG RESET, 48);
		julia_examples();
		return (false);
	}
	if (__have_duplicate(argv[2]) == true || __have_duplicate(argv[3]) == true)
	{
		perror("\nError, contains duplicates");
		return (false);
	}
	return (true);
}
