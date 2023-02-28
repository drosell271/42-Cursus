/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:09:00 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/23 13:27:37 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count])
	{
		if (s[count] == (char) c)
			return ((char *)(s + count));
		count++;
	}
	if (s[count] == (char) c)
		return ((char *)(s + count));
	return (NULL);
}
