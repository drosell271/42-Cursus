/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:30:17 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/23 13:33:05 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		lenght;
	char	*s2;
	char	*s3;

	if (!s1)
		return (NULL);
	s2 = (char *) s1;
	lenght = ft_strlen(s2);
	s3 = ft_calloc(lenght + 1, sizeof(char));
	if (!s3)
		return (NULL);
	ft_memcpy(s3, s2, lenght);
	return (s3);
}
