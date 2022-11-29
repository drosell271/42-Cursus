/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:14:44 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/30 12:41:57 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		a;
	int			b;
	int			c;

	a = 0;
	b = 0;
	c = 0;
	if (!dest && size == 0)
		return (0);
	while (dest[a] != '\0' && a <= size)
		a++;
	while (src[b] != '\0')
		b++;
	if (size <= a)
		return (b + size);
	while (src[c] != '\0' && (a + c) < (size - 1))
	{
		dest[a + c] = src[c];
		c++;
	}
	dest[a + c] = '\0';
	return (b + a);
}
