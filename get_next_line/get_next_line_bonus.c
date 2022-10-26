/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:23:42 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/26 17:54:40 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*changer(char *input_1, char *input_2)
{
	char	*output;

	output = ft_strjoin(input_1, input_2);
	free(input_1);
	return (output);
}

static char	*reader(int fd, char *input)
{
	int		readed;
	char	*temp;

	if (input == NULL)
		input = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE +1, sizeof(char));
	if (!temp)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, temp, BUFFER_SIZE);
		if (readed == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[readed] = 0;
		input = changer(input, temp);
		if (ft_strchr(input, '\n'))
			break ;
	}
	free(temp);
	return (input);
}

char	*new_line(char *input)
{
	char	*temp;
	int		count;

	count = 0;
	if (!input[count])
		return (NULL);
	while (input[count] && input[count] != '\n')
		count++;
	temp = NULL;
	temp = ft_calloc(count + 2, sizeof(char));
	count = 0;
	while (input[count] && input[count] != '\n')
	{
		temp[count] = input[count];
		count++;
	}
	if (input[count] && input[count] == '\n')
		temp[count] = '\n';
	return (temp);
}

char	*cleaner(char *text)
{
	char	*aux;
	int		counter;
	int		counter_aux;

	counter = 0;
	while (text[counter] && text[counter] != '\n')
		counter++;
	if (!text[counter])
	{
		free(text);
		return (NULL);
	}
	aux = NULL;
	if (text[counter] == '\n')
		counter++;
	aux = ft_calloc((ft_strlen(text) - counter) + 1, sizeof(char));
	if (!aux)
		return (NULL);
	counter_aux = 0;
	while (text[counter])
		aux[counter_aux++] = text[counter++];
	free(text);
	return (aux);
}

char	*get_next_line(int fd)
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
