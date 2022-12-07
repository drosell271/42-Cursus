/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:24:19 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/07 18:36:50 by drosell-         ###   ########.fr       */
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
	print_floor(img);
	print_walls(img);
	print_objects(img);
	print_player(img);
	print_exit(img);
	return (0);
}
