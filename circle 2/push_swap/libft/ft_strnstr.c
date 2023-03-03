/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:59:54 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/23 14:04:14 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	contador;

	if (!big && len == 0)
		return (NULL);
	if (*little == 0 || big == little)
		return ((char *)big);
	contador = ft_strlen(little);
	while (*big && contador <= len--)
	{
		if (!(ft_strncmp((char *)big, (char *)little, contador)))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
