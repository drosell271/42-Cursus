/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:26:43 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/26 19:15:59 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size_calculator(char const *s1, char const *set)
{
	int		s1_counter;
	int		set_counter;
	int		output_counter;
	int		size;

	s1_counter = 0;
	set_counter = 0;
	output_counter = 0;
	size = 0;
	while(s1[s1_counter])
	{
		while(set[set_counter])
		{
			if(s1[s1_counter] != set[set_counter] && set_counter == ft_strlen(set))
				size++;
			set_counter++;
		}
		set_counter = 0;
		s1_counter++;
	}
	return (size);
}

char	*generate_output(char *output, char const s1, char const set)
{
	int		s1_counter;
	int		set_counter;
	int		output_counter;

	s1_counter = 0;
	set_counter = 0;
	output_counter = 0;
	while(s1[s1_counter])
	{
		while(set[set_counter])
		{
			if(s1[s1_counter] != set[set_counter] && set_counter == ft_strlen(set))
				output[output_counter] = (char) s1[s1_counter];
			set_counter++;
		}
		set_counter = 0;
		s1_counter++;
	}
	return (output);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	int		size;

	s1_counter = 0;
	set_counter = 0;
	output_counter = 0;
	size = 0;
	size = size_calculator(s1, set);
	output = ft_calloc(size, sizeof(char));
	return (generate_output(output, s1, set));
}

	


	









}
