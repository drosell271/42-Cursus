/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:26:43 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/16 15:04:39 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*output_pa_recortar(char *output, int start, int end, char const *s1)
{
	int	size;

	size = 0;
	if (output)
	{
		while (start <= end)
		{
			output[size] = s1[start];
			start++;
			size++;
		}
		return (output);
	}
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	int		start;
	int		end;

	start = 0;
	if (s1 && set)
	{
		end = ft_strlen(s1) - 1;
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (end >= 0 && ft_strrchr(set, s1[end]))
			end--;
		if (end <= 0)
			return (ft_strdup(""));
		output = ft_calloc (end - start + 2, sizeof(char));
		return (output_pa_recortar (output, start, end, s1));
	}
	return (NULL);
}
