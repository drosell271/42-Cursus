/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:38:10 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/07 19:07:42 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_init(t_player *player)
{
	player->pos_x = 0;
	player->pos_y = 0;
	player->objects_total = 0;
	player->direction = 'D';
	player->moves = 0;
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 13 || keycode == 126)
		move_player(img, 'U');
	else if (keycode == 0 || keycode == 123)
		move_player(img, 'L');
	else if (keycode == 1 || keycode == 125)
		move_player(img, 'D');
	else if (keycode == 2 || keycode == 124)
		move_player(img, 'R');
	else if (keycode == 53)
		close_cross(img);
	return (0);
}

int	move_player(t_data *img, char direction)
{
	int		action;

	ft_printf("Moving %c\n ", direction);
	img->player.direction = direction;
	action = check_object(img, obtain_object(img, direction));
	if (action == 1)
	{
		if (direction == 'U')
			img->map.map[img->player.pos_y - 1][img->player.pos_x] = 'P';
		else if (direction == 'D')
			img->map.map[img->player.pos_y + 1][img->player.pos_x] = 'P';
		else if (direction == 'L')
			img->map.map[img->player.pos_y][img->player.pos_x - 1] = 'P';
		else if (direction == 'R')
			img->map.map[img->player.pos_y][img->player.pos_x + 1] = 'P';
		img->map.map[img->player.pos_y][img->player.pos_x] = '0';
	}
	if (action == 2)
	{
		ft_printf("JUEGO TERMINADO");
		exit (0);
	}
	return (0);
}

int	check_object(t_data *img, char object)
{
	if (object == '1')
		return (0);
	else if (object == 'E')
	{
		if (img->player.objects_total != 0)
			return (0);
		else if (img->player.objects_total == 0)
			return (2);
	}
	else if (object == 'C')
		return (1);
	return (1);
}

char	obtain_object(t_data *img, char direction)
{
	char	output;

	if (direction == 'U')
		output = img->map.map[img->player.pos_y - 1][img->player.pos_x];
	else if (direction == 'D')
		output = img->map.map[img->player.pos_y + 1][img->player.pos_x];
	else if (direction == 'L')
		output = img->map.map[img->player.pos_y][img->player.pos_x - 1];
	else if (direction == 'R')
		output = img->map.map[img->player.pos_y][img->player.pos_x + 1];
	else
		output = '\0';
	return (output);
}
