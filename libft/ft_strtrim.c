/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:26:43 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/26 19:15:59 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	int		data[4];	//counter, size, init, last

	ft_bzero(data, 4);
	while(s1[data[0]])
	{
		if ((char) s1[data[0]] != (char) set)
		{	
			data[1]++;
			data[2] = data[0];
		}
		if ((char) s1[data[0]] == (char)set && (char) data[2] != 0)
			data[3] = data[0] - 1;
		data[0]++;
	}
	data[0] = 0;
	output = ft_calloc(data[1], sizeof(char));
	while (data[2] < data[3])
	{
		output [data[0]] = (char) s1[data[2]];
		data[0]++;
		data[2]++;
	}
	return (output);
}
