/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:33:03 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/29 19:30:56 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	print_floor(t_data *img, int size_x, int size_y)
{	
	int	width;
	int	height;
	int	x;
	int	y;

	x = 0;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, size_x * 64, size_y * 64, "So_Long");
	img->img = mlx_xpm_file_to_image(img->mlx,
			"../Assets/suelo.xpm", &width, &height);
	while (x <= size_x)
	{
		y = 0;
		while (y <= size_y)
		{
			mlx_put_image_to_window(
				img->mlx, img->win, img->img, x * 64, y * 64);
			y++;
		}
		x++;
	}
	mlx_destroy_image(img->mlx, img->img);
}

void	print_walls(t_data *img, char **map, int size_x, int size_y)
{
	int	width;
	int	height;
	int	x;
	int	y;
	int	rand;

	x = 0;
	while (x <= size_x)
	{
		y = 0;
		while (y <= size_y)
		{
			rand = x % 4;
			img->img = mlx_xpm_file_to_image(img->mlx,
					select_wall(rand), &width, &height);
			if (map[x][y] == '1')
			{
				mlx_put_image_to_window(
					img->mlx, img->win, img->img, x * 64, y * 64);
				mlx_destroy_image(img->mlx, img->img);
			}
			y++;
		}
		x++;
	}
}

void	print_objects(t_data *img, char **map, int size_x, int size_y)
{
	int	width;
	int	height;
	int	x;
	int	y;
	int	rand;

	x = 0;
	while (x <= size_x)
	{
		y = 0;
		while (y <= size_y)
		{
			rand = x % 4;
			img->img = mlx_xpm_file_to_image(img->mlx,
					select_object(rand), &width, &height);
			if (map[x][y] == 'C')
			{
				mlx_put_image_to_window(
					img->mlx, img->win, img->img, x * 64, y * 64);
				mlx_destroy_image(img->mlx, img->img);
			}
			y++;
		}
		x++;
	}
}

void	print_others(t_data *img, char **map, int size_x, int size_y)
{
	int	width;
	int	height;
	int	x;
	int	y;

	while (x <= size_x)
	{
		y = 0;
		while (y <= size_y)
		{
			img->img = mlx_xpm_file_to_image(img->mlx,
					select_other(map[x][y]), &width, &height);
			if (map[x][y] == 'E' || map[x][y] == 'P')
			{
				mlx_put_image_to_window(
					img->mlx, img->win, img->img, x * 64, y * 64);
				mlx_destroy_image(img->mlx, img->img);
			}
			y++;
		}
		x++;
	}
}

int	print_map(char **map, int size_x, int size_y)
{
	t_data	img;

	print_floor(&img, size_x, size_y);
	print_walls(&img, map, size_x, size_y);
	print_objects(&img, map, size_x, size_y);
	print_others(&img, map, size_x, size_y);
	mlx_loop(img.mlx);
}
