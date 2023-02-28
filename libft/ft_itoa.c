/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:40:05 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/02 17:00:29 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_size(int n, int size)
{
	if (n < 0)
	{
		if (n == -2147483648)
			return (12);
		size++;
		n = n * -1;
	}
	if (n >= 10)
	{
		size++;
		return (check_size(n / 10, size));
	}
	if (n < 10)
		size++;
	return (size + 1);
}

char	*create_output(int n, int size, char *output)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_strlcpy(output, "-2147483648", 12);
			return (output);
		}
		output[0] = '-';
		n = n * -1;
	}
	while (n >= 10)
	{
		output[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	output[size] = n + '0';
	return (output);
}

char	*ft_itoa(int n)
{
	char	*output;
	int		size;

	size = check_size(n, 0);
	output = ft_calloc (size, sizeof(char));
	if (output)
	{
		output = create_output (n, size - 2, output);
		return (output);
	}
	return (NULL);
}
