/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:52:25 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/15 19:13:05 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refill(char **output, char *input)
{
}

void	create_map(int size_x, int size_y, char **output)
{
}

int	get_size_x(char *input)
{
	int		fd;
	int		x_size;
	int		temp_size;
	char	*temp;

	fd = open(input, O_RDONLY);
	temp = get_next_line(fd);
	x_size = ft_strlen(temp);
	if (temp[x_size - 1] == '\n')
		x_size --;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		temp_size = ft_strlen(temp);
		if (temp[temp_size - 1] == '\n')
			temp_size--;
		if (x_size != temp_size)
			x_size = -1;
	}
	close(fd);
	free(temp);
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
		temp = get_next_line(fd);
		y_size++;
	}
	close(fd);
	return (y_size);
}

char	**generate_new_map(char	*input)
{
	char	**output;
	int		size_x;
	int		size_y;

	size_x = get_size_x(input);
	size_y = get_size_y(input);
	printf("\nX: %d | Y: %d", size_x, size_y);
	/*if (size_x == -1 || size_y == -1)
		return (NULL);
	create_map(size_x, size_y, output);
	refill (output, input);
	if (check_map(output) == 0)
		return (output);
	free(output);*/
	return (NULL);
}