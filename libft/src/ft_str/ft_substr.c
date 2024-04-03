/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:08:22 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/03 22:23:28 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		start = ft_strlen(s);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = 0;
	return (sub);
}

/*int main(int argc, char **argv)
{
    int ret_atoi1;
    int ret_atoi2;

    if (argc > 3)
    {
        ret_atoi1 = atoi(argv[2]);
        ret_atoi2 = atoi(argv[3]);
        printf("L'extraction obtenue est: %s\n", ft_substr(argv[1],
				ret_atoi1, ret_atoi2));
    }
}*/
