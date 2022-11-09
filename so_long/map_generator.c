/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:11 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/09 17:35:18 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	y_size_calculator(char *argv)
{
	char	*check_line;
	int		y_size;
	int		fd;

	y_size = 1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	check_line = get_next_line(fd);
	while (check_line)
	{
		y_size++;
		check_line = get_next_line(fd);
	}
	close(fd);
	return (y_size);
}

int	x_size_calculator(char *argv)
{
	char	*check_line;
	int		x_size;
	int		fd;

	x_size = 1;

	fd = open(argv, O_RDONLY);

	if (fd == -1)
		return (-1);
	
	check_line = get_next_line(fd);
	x_size = ft_strlen(check_line);
	while (check_line)
	{
		check_line = get_next_line(fd);
		if ((int) ft_strlen(check_line) != x_size)
		{
			x_size = -1;
			break;
		}
	}
	close(fd);
	return (x_size);	
}

void	**map_generator(int x_size, int y_size, char **map)
{
	int counter;

	map = ft_calloc(x_size, sizeof(char *));
	counter = 0;
	while (counter <= x_size)
	{
		map[counter] = ft_calloc(y_size, sizeof(char));
		counter++;
 	}
		//Falta comprobar que se ha creado bien el calloc
}

char	**file_2_map(char *argv)
{
	char	**map;
	int		y_size;
	int		x_size;
	
	x_size = x_size_calculator(argv);
	y_size = y_size_calculator(argv);
	if (y_size == -1 || x_size == -1)
		return (NULL);
	map_generator(x_size, y_size, map);
	//Falta rellenar el map
	map_filler()

}