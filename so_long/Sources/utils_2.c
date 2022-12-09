/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:24:19 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/09 16:06:59 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*select_exit(t_player *player)
{
	char	*output;

	if (player->objects_total != 0)
		output = "./Assets/salida_pendiente.xpm";
	else if (player->objects_total == 0)
		output = "./Assets/salida_abierta.xpm";
	else
		output = NULL;
	return (output);
}

int	render_frame(t_data *img)
{
	char	*objetos;
	char	*movimientos;

	objetos = ft_itoa(img->player.objects_total);
	movimientos = ft_itoa(img->player.total_movements);
	mlx_clear_window(img->mlx, img->win);
	print_floor(img);
	print_walls(img);
	print_objects(img);
	print_player(img);
	print_exit(img);
	mlx_string_put(img->mlx, img->win, 10, 10,
		0x00FF0000, "Objetos restantes: ");
	mlx_string_put(img->mlx, img->win, 190, 10,
		0x00FF0000, objetos);
	mlx_string_put(img->mlx, img->win, 10, 30,
		0x000000FF, "Movimientos realizados: ");
	mlx_string_put(img->mlx, img->win, 240, 30,
		0x000000FF, movimientos);
	free(movimientos);
	free (objetos);
	return (0);
}

void	clean_soround(t_data *img)
{
	if (img->map.map[img->player.pos_y + 1][img->player.pos_x + 1] == 'P')
		img->map.map[img->player.pos_y + 1][img->player.pos_x + 1] = 0;
	else if (img->map.map[img->player.pos_y + 1][img->player.pos_x] == 'P')
		img->map.map[img->player.pos_y + 1][img->player.pos_x] = 0;
	else if (img->map.map[img->player.pos_y + 1][img->player.pos_x - 1] == 'P')
		img->map.map[img->player.pos_y + 1][img->player.pos_x - 1] = 0;
	else if (img->map.map[img->player.pos_y][img->player.pos_x + 1] == 'P')
		img->map.map[img->player.pos_y][img->player.pos_x + 1] = 0;
	else if (img->map.map[img->player.pos_y][img->player.pos_x] == 'P')
		img->map.map[img->player.pos_y][img->player.pos_x] = 0;
	else if (img->map.map[img->player.pos_y][img->player.pos_x - 1] == 'P')
		img->map.map[img->player.pos_y][img->player.pos_x - 1] = 0;
	else if (img->map.map[img->player.pos_y - 1][img->player.pos_x + 1] == 'P')
		img->map.map[img->player.pos_y - 1][img->player.pos_x + 1] = 0;
	else if (img->map.map[img->player.pos_y - 1][img->player.pos_x] == 'P')
		img->map.map[img->player.pos_y - 1][img->player.pos_x] = 0;
	else if (img->map.map[img->player.pos_y - 1][img->player.pos_x - 1] == 'P')
		img->map.map[img->player.pos_y - 1][img->player.pos_x - 1] = 0;
	return ;
}
