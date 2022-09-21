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
	size_t	count_small;

	while (big[count_big])
	{
		while (small[count_small])
		{
			if (big[count_big + count_small] == small[count_small])

			count_small++;
		}
		count_small = 0;
		count_big++;
	}
	return (NULL);
}
