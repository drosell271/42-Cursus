/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:24:24 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/14 12:31:29 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	if (!dest && !src)
		return (NULL);
	while (count < n)
	{
	((unsigned char *) dest)[count] = ((unsigned char *) src)[count];
	count++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

char	*ft_strlcat(char *dest, const char *src, size_t size)
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
		return (dest);
	while (src[c] != '\0' && (a + c) < (size - 1))
	{
		dest[a + c] = src[c];
		c++;
	}
	dest[a + c] = '\0';
	return (dest);
}

void	ft_bzero(void *s, int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		((unsigned char *) s)[count] = '\0';
		count++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*salida;
	unsigned int	total_b;

	total_b = count * size;
	if (total_b && total_b / count != size)
		return (NULL);
	salida = malloc(total_b);
	if (!salida)
		return (NULL);
	ft_bzero(salida, total_b);
	return (salida);
}

