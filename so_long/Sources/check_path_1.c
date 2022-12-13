/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:55:51 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/13 17:05:41 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_map *map)
{
	t_search	search;
	int			target;

	target = 0;
	get_num_objects(map);
	get_objects_coords(map);
	get_player(map);
	while (target <= map->target_number)
	{
		if (search_path(map, &search, target) == -1)
		{
			ft_printf("NO EXISTE CAMINO POSIBLE :(\n");
			exit(0);
		}
		target++;
	}
	free(map->target_x);
	free(map->target_y);
	return ;
}

void	get_num_objects(t_map *map)
{
	int	x;
	int	y;
	int	c;

	y = -1;
	c = 0;
	while (++y < map->size_y)
	{
		x = -1;
		while (++x <= map->size_x)
		{
			if (map->map[y][x] == 'C')
			{
				c++;
			}
		}
	}
	map->target_number = c;
	map->target_x = ft_calloc(c + 2, sizeof(int));
	map->target_y = ft_calloc(c + 2, sizeof(int));
}

void	get_objects_coords(t_map *map)
{
	int	x;
	int	y;
	int	c;

	y = -1;
	c = 0;
	while (++y < map->size_y)
	{
		x = -1;
		while (++x <= map->size_x)
		{
			if (map->map[y][x] == 'C' || map->map[y][x] == 'E')
			{
				map->target_x[c] = x;
				map->target_y[c] = y;
				c++;
			}
		}
	}
}

void	get_player(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->size_y)
	{
		x = -1;
		while (++x <= map->size_x)
		{
			if (map->map[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
		}
	}
}

int	obtain_distance(int x_a, int y_a, int x_b, int y_b)
{
	int	out;

	out = 0;
	out = sqrt(pow((x_b - x_a), 2) + pow((y_b - y_a), 2));
	return (out);
}