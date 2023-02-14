/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:55:49 by drosell-          #+#    #+#             */
/*   Updated: 2023/02/14 16:43:27 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(t_map *input)
{
	char	**new_map;
	int		x;
	int		y;

	new_map = new_map_generator(input);
	new_map_filler_1(input, new_map);
	new_map_filler_2(input, new_map);
	y = 0;
	while (y < input->size_y)
	{
		x = 0;
		while (x < input->size_x)
		{
			if (new_map[y][x] != 'O'
			&& new_map[y][x] != 'X'
			&& new_map[y][x] != 'E')
				return (-1);
			x++;
		}
		y++;
	}
	y = 0;
	/*while (y < input->size_y)
	{
		ft_printf("%s\n", new_map[y]);
		y++;
	}*/
	return (1);
}

char	**new_map_generator(t_map *input)
{
	char	**new_map;
	int		x;
	int		y;

	new_map = ft_calloc(input->size_y + 1, sizeof(char *));
	y = 0;
	x = 0;
	while (y < input->size_y)
	{
		new_map[y] = ft_calloc(input->size_x + 1, sizeof(char));
		while (x < input->size_x)
		{
			new_map[y][x] = 'X';
			x++;
		}
		x = 0;
		y++;
	}
	return (new_map);
}

void	new_map_filler_1(t_map *input, char **new_map)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y < input->size_y - 1)
	{
		while (x < input->size_x - 1)
		{
			{
				if (input->map[y][x] != '0' && input->map[y][x] != '1')
				{
					if (input->map[y][x] == 'P')
						new_map[y][x] = 'O';
					else
						new_map[y][x] = input->map[y][x];
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	new_map_filler_2(t_map *input, char **new_map)
{
	int		x;
	int		y;
	int		mods;

	x = 1;
	mods = 1;
	while (mods != 0)
	{
		mods = 0;
		y = 1;
		while (y < input->size_y - 1)
		{
			x = 1;
			while (x < input->size_x - 1)
			{
				if (check_if(input, new_map, x, y) == 1)
				{
					new_map[y][x] = 'O';
					mods++;
				}
				x++;
			}
			y++;
		}
	}
}

int	check_if(t_map *input, char **new_map, int x, int y)
{
	if ((new_map[y + 1][x] == 'O' || new_map[y - 1][x] == 'O'
		|| new_map[y][x + 1] == 'O' || new_map[y][x - 1] == 'O')
		&& input->map[y][x] != '1' && new_map[y][x] != 'O'
		&& new_map[y][x] != 'E')
	{
		return (1);
	}	
	return (0);
}
