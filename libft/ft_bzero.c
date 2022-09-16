/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:57:00 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/16 09:57:03 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	count;
	unsigned char	*cast;

	count = 0;
	cast = (unsigned char *)s;
	while (count <= n)
	{
		cast[count] = '\0';
		count++;
	}
}
