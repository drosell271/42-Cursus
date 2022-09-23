/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:35:08 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/23 17:10:08 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t		count;

	count = 0;
	result = ft_calloc(len, sizeof(char));
	while (count < len && s[start + count])
	{
		result[count] = (char) s[start + count];
		count++;
	}
	return (result);
}