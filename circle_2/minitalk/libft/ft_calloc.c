/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:47:00 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/30 13:36:42 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
