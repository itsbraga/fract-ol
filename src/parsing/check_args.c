/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:28 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/01 14:11:04 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static bool	__is_only_double(char *argv)
{
	int		i;
	bool	has_decimal;

	i = 0;
	has_decimal = false;
	if (argv[0] == 0 || argv[0] == '.' || argv[0] == ',')
		return (false);
	if (argv[i] == '-' && argv[i + 1])
		i++;
	if (ft_isdigit(argv[i]) == false && ft_isdigit(argv[i + 1]) == false)
		return (false);
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

bool	check_julia_args(char **argv)
{
	const char	*mandatory = {"./fractol"};
	const char	*bonus = {"./fractol_bonus"};

	if (__is_only_double(argv[2]) == false
		|| __is_only_double(argv[3]) == false)
	{
		ft_putstr_fd("Error: Invalid argument. Should be decimal.\n\n", 2);
		ft_putstr_fd(BOLD EX_HEADER RESET EXAMPLE_MSG, 1);
		if (ft_strncmp(argv[0], mandatory, 9) == 0)
			julia_examples();
		else if (ft_strncmp(argv[0], bonus, 15) == 0)
			julia_examples_bonus();
		return (false);
	}
	if (__have_duplicate(argv[2]) == true || __have_duplicate(argv[3]) == true)
	{
		ft_putstr_fd("Error: Contains duplicates.\n", 2);
		return (false);
	}
	return (true);
}
