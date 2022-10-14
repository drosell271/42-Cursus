/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:23:42 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/14 12:38:31 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_fd(int fd)
{
	if (fd > 2)
		return (1);
	return (0);
}

char	*resize(char *input, int add_size)
{
	char	*output;
	
	output = ft_calloc((ft_strlen(input) + add_size), sizeof(char));
	ft_memcpy(output, input, ft_strlen(input));
	free (input);
	return (output);
}

char	*push_to_output(char *input, char *output)
{
	output = resize(output, ft_strlen(input));
	return (ft_memcpy(output, input, ft_strlen(input)));
}

char	*get_next_line(int fd)
{
	char	*output;
	char	*temp;
	int		counter;

	temp = ft_calloc(BUFFER_SIZE, sizeof(char));
	output = ft_calloc(1, sizeof(char));
	counter = 1;
	if (check_fd(fd) == 1)
	{
		read(fd, &temp[0], 1);
		while (1)
		{
			read(fd, &temp[counter], 1);
			if (temp[counter] == '\n')
				break ;
			if (counter == BUFFER_SIZE)
				push_to_output(temp, output);
			counter++;
		}
		push_to_output(temp, output);
		return (output);
	}
	free(output);
	return (NULL);
}


