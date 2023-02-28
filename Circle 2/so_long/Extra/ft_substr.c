/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:35:08 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/30 13:18:49 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	count;

	count = 0;
	if (s)
	{
		if (start >= ft_strlen(s))
			len = 0;
		else if ((ft_strlen(s) - start) < len)
			len = ft_strlen(s) - start;
		result = ft_calloc(len + 1, sizeof(char));
		if (!result)
			return (NULL);
		while (count < len)
		{
			result[count] = (char) s[start + count];
			count++;
		}
		return (result);
	}
	return (NULL);
}
