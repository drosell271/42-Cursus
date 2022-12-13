/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:55:51 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/13 17:48:04 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_path(t_map *map, t_search *search, int target)
{
	search->id = 0;
	search->level = 0;
	search->distance = obtain_distance(map->player_x, map->player_y,
			map->target_x[target], map->target_y[target]);
	search->position_x = map->player_x;
	search->position_y = map->player_y;
	search->destination_x = map->target_x[target];
	search->destination_y = map->target_y[target];
	return (main_search(search));
}

int	main_search(t_search *search)
{
	create_next_nodes(search);
}