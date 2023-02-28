/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:23:42 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/09 15:43:39 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_bonus(int fd)
{
	static char	*text[1024];
	char		*line;

	line = NULL;
	if (read(fd, 0, 0) < 0)
	{
		if (text[fd] != NULL)
		{
			free(text[fd]);
			text[fd] = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	text[fd] = reader(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	line = new_line(text[fd]);
	text[fd] = cleaner(text[fd]);
	return (line);
}
