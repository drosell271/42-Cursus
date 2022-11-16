/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:52:25 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/16 16:00:17 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**refill(int size_x, int size_y, char **output, char *input)
{
	ft_printf("refill\n");
	int		counter_y;
	char	*temp;
	int		fd;

	fd = open(input, O_RDONLY);
	counter_y = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		printf("line %d : %s", counter_y, temp);
		ft_memcpy(output[counter_y], temp, ft_strlen(temp) - 1);
		printf("mine: %d, temp: %d\n", ft_strlen(output[counter_y]), ft_strlen(temp));
		free (temp);
		temp = get_next_line(fd);
		counter_y++;
	}
	free(temp);
	close (fd);
	printf ("\n0 : %s\n1 : %s\n2 : %s\n3 : %s\n\n", output[0], output[1], output[2], output[3]);
}

char	**create_map(int size_x, int size_y)
{
	int		counter;
	char	**output;

	counter = 0;
	output = ft_calloc(size_y, sizeof (char *));
	while (counter < size_y)
	{
		output[counter] = ft_calloc(size_x, sizeof (char));
		counter++;
	}
	return (output);
}

int	get_size_x(char *input)
{
	int		fd;
	int		x_size;
	int		aux_size;
	char	*line;

	fd = open(input, O_RDONLY);
	line = get_next_line(fd);
	x_size = ft_strlen(line);
	if (line[ft_strlen(line) - 1] == '\n')
		x_size = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		aux_size = ft_strlen(line);
		if (line[ft_strlen(line) - 1] == '\n')
			aux_size = ft_strlen(line) - 1;
		if (aux_size != x_size)
		{
			x_size = -1;
			break ;
		}
	}
	free(line);
	close(fd);
	return (x_size);
}

int	get_size_y(char *input)
{
	int		fd;
	int		y_size;
	char	*temp;

	fd = open(input, O_RDONLY);
	temp = get_next_line(fd);
	y_size = 0;
	while (temp)
	{
		if (temp[0] == '\n')
		{
			y_size = -1;
			break ;
		}
		free(temp);
		temp = get_next_line(fd);
		y_size++;
	}
	free(temp);
	close(fd);
	return (y_size);
}

char	**generate_new_map(char	*input)
{
	char	**output;
	int		size_x;
	int		size_y;

	size_y = get_size_y(input);
	size_x = get_size_x(input);
	printf("X: %d | Y: %d \n", size_x, size_y);
	if (size_x == -1 || size_y == -1)
		return (NULL);
	output = create_map(size_x, size_y);
	refill (size_x, size_y, output, input);
	/*if (check_map(output) == 0)
		return (output);
	free(output);*/
	return (NULL);
}
