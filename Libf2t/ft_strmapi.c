/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:21:34 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/26 18:25:04 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	int		i;

	i = 0;
	if (!f)
		return (ft_calloc (1, sizeof(char)));
	if (!s || !f)
		return (NULL);
	output = ft_calloc (ft_strlen(s) + 1, sizeof(char));
	if (!output)
		return (NULL);
	while (s[i])
	{
		output[i] = f(i, s[i]);
		i++;
	}
	return (output);
}
