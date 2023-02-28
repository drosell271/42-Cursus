/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:27:07 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/30 12:03:14 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**output_x_sizer(char const *s, char c)
{
	char	**output;
	int		trim;
	int		counter;
	int		x_size;

	trim = 0;
	counter = 0;
	x_size = 0;
	while (s[counter])
	{
		if ((char) s[counter] != c && trim == 0)
		{
			trim = 1;
			x_size++;
		}
		if ((char) s[counter] == c)
			trim = 0;
		counter++;
	}
	output = ft_calloc(x_size + 1, sizeof(char *));
	return (output);
}

char	**output_y_sizer(char const *s, char c, char **output)
{
	int	s_counter;
	int	output_pos;
	int	y_size;

	s_counter = 0;
	output_pos = 0;
	y_size = 0;
	while (s[s_counter])
	{
		if ((char) s[s_counter] != c)
			y_size++;
		else if ((char) s[s_counter] == c && y_size != 0)
		{
			output[output_pos] = ft_calloc(y_size + 1, sizeof(char));
			y_size = 0;
			output_pos++;
		}
		s_counter++;
	}
	if (y_size != 0)
		output[output_pos] = ft_calloc(y_size + 1, sizeof(char));
	return (output);
}

char	**output_filler(char const *s, char c, char **output)
{
	int	output_x_counter;
	int	output_y_counter;
	int	s_counter;

	output_x_counter = 0;
	output_y_counter = 0;
	s_counter = 0;
	while (s[s_counter])
	{
		if ((char) s[s_counter] != c)
		{
			output[output_x_counter][output_y_counter] = (char) s[s_counter];
			output_y_counter++;
		}
		if ((char) s[s_counter] == c && output_y_counter != 0)
		{
			output_y_counter = 0;
			output_x_counter++;
		}
		s_counter++;
	}
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;

	if (!s)
		return (NULL);
	output = output_x_sizer(s, c);
	if (!output)
		return (NULL);
	output = output_y_sizer(s, c, output);
	output = output_filler(s, c, output);
	return (output);
}
