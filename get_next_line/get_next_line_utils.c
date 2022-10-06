/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:01:56 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/05 11:01:56 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
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
