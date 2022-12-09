/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:33:03 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/09 16:14:12 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_floor(t_data *img)
{	
	int	width;
	int	height;
	int	x;
	int	y;

	x = -1;
	img->img = mlx_xpm_file_to_image(
			img->mlx, "./Assets/suelo.xpm", &width, &height);
	while (++x < img->map.size_x)
	{
		y = -1;
		while (++y < img->map.size_y)
		{
			mlx_put_image_to_window(
				img->mlx, img->win, img->img, x * 64, y * 64);
		}
	}
	mlx_destroy_image(img->mlx, img->img);
}

void	print_walls(t_data *img)
{
	int	width;
	int	height;
	int	x;
	int	y;

	y = -1;
	while (++y < img->map.size_y)
	{
		x = -1;
		while (++x <= img->map.size_x)
		{
			if (img->map.map[y][x] == '1')
			{
				img->img = mlx_xpm_file_to_image(img->mlx,
						select_wall((x + y) % 4), &width, &height);
				mlx_put_image_to_window(img->mlx,
					img->win, img->img, x * 64, y * 64);
				mlx_destroy_image(img->mlx, img->img);
			}
		}
	}
}

void	print_objects(t_data *img)
{
	int	width;
	int	height;
	int	x;
	int	y;

	y = -1;
	img->player.objects_total = 0;
	while (++y < img->map.size_y)
	{
		x = -1;
		while (++x <= img->map.size_x)
		{
			if (img->map.map[y][x] == 'C')
			{
				img->img = mlx_xpm_file_to_image(img->mlx,
						select_object((x + y) % 4), &width, &height);
				img->player.objects_total++;
				mlx_put_image_to_window(
					img->mlx, img->win, img->img, (x * 64) + 16, (y * 64) + 16);
				mlx_destroy_image(img->mlx, img->img);
			}
		}
	}
}

void	print_player(t_data *img)
{
	int	width;
	int	height;
	int	x;
	int	y;

	y = -1;
	while (++y < img->map.size_y)
	{
		x = -1;
		while (++x <= img->map.size_x)
		{
			if (img->map.map[y][x] == 'P')
			{
				img->player.pos_x = x;
				img->player.pos_y = y;
				img->img = mlx_xpm_file_to_image(img->mlx,
						select_direction(&img->player), &width, &height);
				mlx_put_image_to_window(
					img->mlx, img->win, img->img, (x * 64) + 4, (y * 64) + 4);
				mlx_destroy_image(img->mlx, img->img);
			}
		}
	}
}

void	print_map(t_map *map)
{
	t_data		img;
	t_player	player;

	player_init(&player);
	img.player = player;
	img.player.total_movements = 0;
	img.map = *map;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.map.size_x * 64,
			img.map.size_y * 64, "So_Long");
	print_floor(&img);
	print_walls(&img);
	print_objects(&img);
	print_player(&img);
	print_exit(&img);
	ft_printf ("-----------------------------\n");
	ft_printf ("Movimientos realizados: %d\n", img.player.total_movements);
	ft_printf("Objetos restantes %d\n", img.player.objects_total);
	ft_printf ("-----------------------------\n\n");
	mlx_hook(img.win, 17, 1L << 0, close_cross, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_loop_hook(img.mlx, render_frame, &img);
	mlx_loop(img.mlx);
}
