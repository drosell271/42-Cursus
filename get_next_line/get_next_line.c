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



char	*insert(char *buffer,char *output)
{
	int		size;
	char	*new_output;

	size = ft_strlen(buffer);
	if (output != NULL)
	{
		new_output = ft_calloc(size + ft_strlen(output), sizeof(char));
		ft_memcpy(new_output, output, ft_strlen(output));
		free(output);
		ft_strlcat(new_output, buffer, size + ft_strlen(new_output));
	}
	else
	{
		(void) output;
		new_output = ft_calloc(size, sizeof(char));
		ft_memcpy(new_output, buffer, size);
	}
	return (new_output);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*output;
	char	character;
	long	counter;
	
	counter = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read(fd, &character, 1);
	buffer[0] = character;
	while(character != '\0' || character != -1)
	{
		read(fd, &character, 1);
		buffer[counter] = character;
		if (counter == BUFFER_SIZE)
		{
			output = insert(buffer, output);
			counter = -1;
		}
		if (character == '\n')
		{
			output = insert(buffer, output);
			break;
		}
		counter++;
	}
	free(buffer);
	return(output);
}


