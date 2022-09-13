/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:40:30 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/13 18:14:26 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *s);

int	strlcpy(char *dst, char *src, int size)
{
	unsigned int	c;
	unsigned int	z;

	z = ft_strlen(src);
	c = 0;
	if (size != 0)
	{
		while (src [c] != '\0' && x < size - 1)
		{
			dest [c] = src [c];
			c++;
		}
	}
	return (z);
}
