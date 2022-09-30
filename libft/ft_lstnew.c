/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:27:07 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/30 13:39:27 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *nuevo)
{
	t_list	*output;

	output = ft_calloc(1, sizeof(t_list));
	if (!output)
		return (NULL);
	(*output).content = nuevo;
	(*output).next = NULL;
	return (output);
}
