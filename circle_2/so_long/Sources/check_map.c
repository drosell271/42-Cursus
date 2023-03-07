/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:57:06 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/09 16:58:21 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_objects(int size_x, int size_y, char **output)
{
	int	c_x;
	int	c_y;
	int	out[2];

	c_y = 0;
	out[0] = 0;
	out[1] = 0;
	while (c_y < size_y)
	{
		c_x = 0;
		while (c_x < size_x)
		{
			if (output[c_y][c_x] == 'E' || output[c_y][c_x] == 'P')
				out[0]++;
			else if (output[c_y][c_x] == 'C')
				out[1]++;
			else if (output[c_y][c_x] != '0' && output[c_y][c_x] != '1')
				return (-1);
			c_x++;
		}
		c_y++;
	}
	if (out[0] != 2 || out[1] == 0)
		return (-1);
	return (1);
}

int	check_border(int size_x, int size_y, char **output)
{
	int	c_x;
	int	c_y;

	c_y = 0;
	while (c_y < size_y)
	{
		c_x = 0;
		while (c_x < size_x)
		{
			if ((c_y == 0 || c_y == size_y - 1) && output[c_y][c_x] != '1')
				return (-1);
			else if ((c_x == 0 || c_x == size_x - 1) && output[c_y][c_x] != '1')
				return (-1);
			c_x++;
		}
		c_y++;
	}
	return (1);
}

int	check_map_1(int size_x, int size_y, char **output)
{
	if (size_x < 2 || size_y < 2)
	{
		ft_printf("EL MAPA ES DEMASIADO PEQUEÑO :(\n");
		return (-1);
	}
	if (size_x == size_y)
	{
		ft_printf("EL MAPA ES CUADRADO :(\n");
		return (-1);
	}
	if (check_border(size_x, size_y, output) == -1)
	{
		ft_printf("LOS BORDES ESTÁN MAL :(\n");
		return (-1);
	}	
	return (1);
}

int	check_map_2(int size_x, int size_y, char **output)
{
	if (get_objects(size_x, size_y, output) == -1)
	{
		ft_printf("FALTAN O SOBRAN OBJETOS :(\n");
		return (-1);
	}
	return (1);
}
