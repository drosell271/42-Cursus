/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:25:44 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/16 18:06:03 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	signo(int *var, const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] == '+')
		{
			var[0]++;
			var[1] = 1;
		}
		if (str[c] == '-')
		{
			var[0]++;
			var[1] = -1;
		}
		c++;
	}
	return (var);
}

int	num(int *var, const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (var[2] == -1 && str[c] >= '0' && str[c] <= '9')
			var[2] = c;
		c++;
	}
	return (var);
}

int	leter(int *var, const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] < '0' || str[c] > '9')
		{
			if (c < str[2])
			{
				if (str[c] != ' ' || str[c] != '\t' || str[c] != '\n'
					|| str[c] != '\v' || str[c] != '\f' || str[c] != '\r')
					var[3] = c;
			}
			else if (c > str[2])
				var[3] = c;
		}
	}
	return (var);
}

int	atoi(const char *str)
{
	int	[4]	var;
	int		c;
	int		result;

	c = 0;
	result = 0;
	var = {0, 0, -1, 0};
	var = signo(var, str);
	var = num(var, str);
	var = leter(var, str);
	if (var[0] > 1)
		return (0);
	else if (var[2] > var[3])
		return (0);
	c = var[2];
	while (c <= var[3])
	{
		result = str[c] + result * 10;
		c++;
	}
	return (result * var[1]);
}
