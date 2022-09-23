/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:14:44 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/23 13:42:24 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t		a;
	int			b;
	int			c;

	a = 0;
	b = 0;
	c = 0;
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
