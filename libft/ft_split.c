/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:24:33 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/27 19:19:03 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t sepatarator_sizer(char const *s, char c)
{
	size_t	size;
	int	counter;

	size = 0;
	counter = 0;
	while(s[counter])
	{
		if ((char) s[counter] == c)
			size++;
		counter++;
	}
	return (size);
}

int	*sepatarator_generator(char const *s, char c, int *separator)
{
	int	counter_s;
	int	counter_separator;

	counter_s = 0;
	counter_separator = 0;
	while(s[counter_s])
	{
		if ((char) s[counter_s] == c)
		{
			separator[counter_separator] = counter_s;
			counter_separator++;
		}
		counter_s++;
	}
	return (separator);
}

int	output_x_sizer(int *separator)
{
	size_t	size;
	int		counter;
	
	counter = 1;
	size = 0;
	while (separator[counter])
	{
		if (separator[counter] - separator[counter - 1] > 1)
			size++;
		counter++;
	}
	return (size);
}

char **output_y_sizer(int *separator, char **output)
{
	int	counter_separator;
	int counter_output;

	counter_separator = 0;
	counter_output = 0;
	while (separator[counter_separator])
	{
		if (separator[counter_separator] - separator[counter_separator - 1] > 1)
		{
			output[counter_output] = ft_calloc(separator[counter_separator] - separator[counter_separator - 1], sizeof(char));
			counter_output++;
		}
		counter_separator++;
	}
	return (output);
}

char	**ft_split(char const *s, char c)
{
	int	*separator;
	char **output;
	int	*data;	//s, separator, output_x, output_y

	data = ft_calloc(4,sizeof(int));
	separator = ft_calloc(sepatarator_sizer(s, c), sizeof(int));
	separator = sepatarator_generator(s, c, separator);
	output = ft_calloc(output_x_sizer(separator), sizeof(char *));
	output = output_y_sizer(separator, output);
	while(separator[data[1] + 1])
	{
		if (separator[data[1] + 1] - separator[data[1]] > 1)
		{
			data[0] = data[1] + 1;
			while (data[0] <= separator[data[1] + 1] - 1)
			{
				output[data[2]][data[3]] = (char) s[data[0]];
				data[0]++;
				data[3]++;
			}
			data[3] = 0;
		}
		data[2]++;
		data[1]++;
	}
	return (output);
}
