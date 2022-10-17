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
		new_output = ft_calloc(ft_strlen(output) + size, sizeof(char));
		printf("E: %s\n", buffer);
		new_output = ft_strlcat(output, buffer, size);
	}
	else
	{
		(void) output;
		new_output = ft_calloc(size + 1, sizeof(char));
		ft_memcpy(new_output, buffer, size);
		printf("F: %s\n", output);
	}
	printf("G\n");
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
	//printf("A\n");
	while(character != '\0')
	{
		read(fd, &character, 1);
		buffer[counter] = character;
		if (counter == BUFFER_SIZE)
		{
			printf("C\n");
			output = insert(buffer, output);
			ft_bzero(buffer, ft_strlen(buffer));
			counter = 0;
		}
		if (character == '\n')
		{
			printf("D\n");
			output = insert(buffer, output);
			break;
		}
		printf("B: %ld\n", counter);
		counter++;
	}
	//printf("H\n");
	free(buffer);
	return(output);
}


