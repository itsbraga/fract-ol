/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rmif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:13:28 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/03 22:23:28 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Removes from the passed list any element the content of which is "equal"
	to the reference data.
*/

void	ft_lst_rmif(t_list **lst, void *data_ref, int (*cmp)())
{
	t_list	*curr;

	curr = *lst;
	if (lst == NULL || *lst == NULL)
		return ;
	if (cmp(curr->content, data_ref) == 0)
	{
		*lst = curr->next;
		free(curr);
		ft_lst_rmif(lst, data_ref, cmp);
	}
	else
	{
		curr = *lst;
		ft_lst_rmif(&curr->next, data_ref, cmp);
	}
}
