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

int *check_pos(const char *big, const char *little, size_t len, int *resultado)
{
	int	count_big;
	int count_little;

	count_big = 0;
	count_little = 0;
	while (!big[count_big])
	{
		while (!little[count_little])
		{
			if (big[count_big + count_little] == little[count_little])
			{
				if (resultado[0] == -1)
					resultado[0] = count_big;
				count_little++;
			}
			break;
		}
		if (count_little == len)
			resultado[1] = 1;
		resultado[0] = -1;
		count_big++;
	}
	return (resultado);
}

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	int check[2];

	check[0] = -1;
	check[1] = 0;
	check = check_pos(big, little, len, check);
	if (check[1] == 1)
	{
		while(big[check[0]])
		
}
