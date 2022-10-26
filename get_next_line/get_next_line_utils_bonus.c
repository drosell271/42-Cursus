/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:24:24 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/26 17:55:00 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

size_t	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*output;
	int		count_s1_output;
	int		count_s2;

	if (!s1 || !s2)
		return (NULL);
	total_size = 0;
	count_s1_output = 0;
	count_s2 = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	output = ft_calloc(total_size + 1, sizeof(char));
	if (!output)
		return (NULL);
	while (s1[count_s1_output])
	{
		output[count_s1_output] = (char) s1[count_s1_output];
		count_s1_output++;
	}
	while (s2[count_s2])
		output[count_s1_output++] = (char) s2[count_s2++];
	return (output);
}

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
