/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:01:53 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/05 11:01:53 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fd_read(fd)
{
	int	last_pos;
	
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	last_pos = read(fd, buffer, BUFFER_SIZE);
	while (last_pos > 0)
	{
		buffer[last_pos] = '\0';

	}
	

}



void	*buffer_to_line()
{

}

void	*line_to_output()
{

}

void	*print_output()
{

}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*output;
	int			line;

	line = 0;
	fd_read(fd);
	buffer_to_line();
	line_to_output();
	print_output();
}
