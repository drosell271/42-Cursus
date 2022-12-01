/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:33:03 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/01 15:30:14 by drosell-         ###   ########.fr       */
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

	(void) y;
	(void) width;
	(void) height;
	ft_printf("GENERANDO SUELO\n");
	x = 0;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, size_x * 64, size_y * 64, "so_Long");
	img->img = mlx_xpm_file_to_image(img->mlx, "./Assets/suelo.xpm", &width, &height);
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
	ft_printf("%s\n", map[0]);
	ft_printf("GENERANDO MUROS\n");
	x = 0;
	while (x < size_x)
	{
		y = 0;
		while (y < size_y)
		{
			ft_printf("%s", map[x][y]);
			if (1 == 1)
			{
				img->img = mlx_xpm_file_to_image(img->mlx,
						select_wall(x % 4), &width, &height);
				mlx_put_image_to_window(img->mlx,
					img->win, img->img, x * 64, y * 64);
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

	ft_printf("GENERANDO OBJETOS\n");
	x = 0;
	while (x <= size_x)
	{
		y = 0;
		while (y <= size_y)
		{
			img->img = mlx_xpm_file_to_image(img->mlx,
					select_object(x % 4), &width, &height);
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

	ft_printf("GENERANDO JUGADOR Y SALIDA\n");
	x = 0;
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

void	print_map(char **map, int size_x, int size_y)
{
	t_data	img;

	(void) map;
	print_floor(&img, size_x, size_y);
	print_walls(&img, map, size_x, size_y);
	//print_objects(&img, map, size_x, size_y);
	//print_others(&img, map, size_x, size_y);
	mlx_loop(img.mlx);
}
