/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:39:07 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/30 17:15:02 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;
	
	if (lst && new)
	{
		temp = lst[0];
		if (temp)
		{
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		else
			lst[0] = new;
	}
	/*if (!lst)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new; 
	CODIGO DE PROS*/
}