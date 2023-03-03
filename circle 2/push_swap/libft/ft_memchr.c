/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:43:41 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/20 11:00:39 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cadena;
	void			*buscado;

	i = 0;
	cadena = (unsigned char *)s;
	buscado = NULL;
	while (i < n)
	{
		if (cadena[i] == (unsigned char)c)
		{
			buscado = &cadena[i];
			break ;
		}
		i++;
	}
	return (buscado);
}
