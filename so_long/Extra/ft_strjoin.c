/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:54:11 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/30 12:42:38 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*output;
	int		count_s1_output;
	int		count_s2;

	if (!s1 || !s2)
		return (NULL);
	total_size = 0;
	count_s1_output = 0;
	count_s2 = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	output = ft_calloc(total_size + 1, sizeof(char));
	if (!output)
		return (NULL);
	while (s1[count_s1_output])
	{
		output[count_s1_output] = (char) s1[count_s1_output];
		count_s1_output++;
	}
	while (s2[count_s2])
		output[count_s1_output++] = (char) s2[count_s2++];
	return (output);
}
