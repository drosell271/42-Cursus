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

char	*insert(char *buffer, char *output)
{
	int		buffer_size;
	int		output_size;
	char	*new_output;

	buffer_size = ft_strlen(buffer);
	output_size = ft_strlen(output);
	if (output != NULL)
	{
		new_output = ft_calloc(buffer_size + output_size, sizeof(char));
		ft_memcpy(new_output, output, output_size);
		ft_strlcat(new_output, buffer, buffer_size + output_size);
	}
	else
	{
		(void)output;
		new_output = ft_calloc(buffer_size, sizeof(char));
		ft_memcpy(new_output, buffer, buffer_size);
	}
	return (new_output);
}

char	*intermedio(char *output, char *buffer, char character, int fd)
{
	int	counter;

	counter = 1;
	while (character)
	{
		read(fd, &character, 1);
		buffer[counter] = character;
		if (counter + 1 == BUFFER_SIZE)
		{
			output = insert(buffer, output);
			ft_bzero(buffer, BUFFER_SIZE);
			counter = -1;
		}
		if (character == '\n')
		{
			output = insert(buffer, output);
			break ;
		}
		counter++;
	}
	return (output);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*output;
	char	character;

	output = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read(fd, &character, 1);
	buffer[0] = character;
	output = intermedio(output, buffer, character, fd);
	free (buffer);
	return (output);
}
