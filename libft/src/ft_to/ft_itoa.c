/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:08:39 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/03 22:23:28 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Description:
	Cette fonction convertit le nombre entier 'n' en une chaîne de caractères
	contenant ce même nombre.

	Valeur de retour:
	- La chaîne de caractères contenant 'n'
	- NULL si l'argument 'n' est invalide et définira errno sur une erreur de
	  type EINVAL
*/

static int	len_digit(long n)
{
	int	len;

	if (n < 0)
		len = 1;
	else
		len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	int		len_d;

	len_d = len_digit(n);
	nb = n;
	res = malloc(sizeof(*res) * (len_d + 1));
	if (!res)
		return (NULL);
	res[len_d] = '\0';
	if (nb == 0)
		res[0] = 48;
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		res[--len_d] = nb % 10 + 48;
		nb /= 10;
	}
	return (res);
}

/*int main(int argc, char **argv)
{
    int argv_c;

    if (argc < 2)
        return (0);
    argv_c = atoi(argv[1]);
    printf("The string contains |%s| in it.", ft_itoa(argv_c));
}*/
