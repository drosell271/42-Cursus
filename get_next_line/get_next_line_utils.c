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

int	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

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

void	ft_bzero(void *s, size_t n)
{
	size_t	count;

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
