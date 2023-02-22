/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:40:30 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/30 12:40:38 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	aux_strlen(const char *s)
{
	int	c;

	c = 0;
	while ((char) s[c] != '\0')
		c++;
	return (c);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	c;
	size_t	z;

	z = aux_strlen(src);
	c = 0;
	if (size != 0)
	{
		while (src [c] != '\0' && c < size - 1)
		{
			dest[c] = (char) src[c];
			c++;
		}
		dest[c] = '\0';
	}
	return (z);
}
