/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:59:54 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/21 08:59:54 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count_big;
	size_t	count_little;

	count_big = 0;
	count_little = 0;
	while(!big[count_big])
	{
		while(!little[count_small])
		{
			if (big[count_big + count_small] == little[count_small])
			{
				
				count_small++;
			}
			break;
		}
		count_small = 0;
		count_big++;
	}
	while(!big[count_big])
	{
		return ((char *) big[count_big]);
		count_big++;
	}
	return (NULL);
}
