/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:52:25 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/18 20:04:35 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**refill(int size_x, int size_y, char **output, char *input)
{
	int		counter_y;
	char	*temp;
	int		fd;

	fd = open(input, O_RDONLY);
	counter_y = 0;
	temp = get_next_line(fd);
	while (counter_y < size_y)
	{
		ft_memcpy(output[counter_y], temp, size_x);
		free (temp);
		temp = get_next_line(fd);
		counter_y++;
	}
	free(temp);
	close (fd);
	return (output);
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
	int		size_x;
	int		temp_size;
	char	*temp;

	fd = open(input, O_RDONLY);
	temp = get_next_line(fd);
	size_x = ft_strlen_no_nl(temp);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (!temp)
			break ;
		temp_size = ft_strlen_no_nl(temp);
		if (temp_size != size_x)
		{
			size_x = -1;
			break ;
		}
	}
	free(temp);
	close (fd);
	return (size_x);
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
	ft_printf("Tamaño del mapa (x: %d | y: %d)\n", size_x, size_y);
	if (size_x == -1 || size_y == -1)
		return (NULL);
	output = create_map(size_x, size_y);
	output = refill (size_x, size_y, output, input);
	if (check_map_1(size_x, size_y, output) == -1
		|| check_map_2(size_x, size_y, output) == -1)
	{
		exit (1);
	}
	return (output);
}
