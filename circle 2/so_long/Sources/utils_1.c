/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:24:19 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/07 16:08:11 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_no_nl(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0' && s[c] != '\n')
		c++;
	return (c);
}

char	*select_wall(int rand)
{
	char	*output;

	if (rand == 0)
		output = "./Assets/arbol_1.xpm";
	else if (rand == 1)
		output = "./Assets/arbol_2.xpm";
	else if (rand == 2)
		output = "./Assets/arbol_3.xpm";
	else if (rand == 3)
		output = "./Assets/piedra.xpm";
	else
		output = NULL;
	return (output);
}

char	*select_object(int rand)
{
	char	*output;

	if (rand == 0)
		output = "./Assets/fruta_1.xpm";
	else if (rand == 1)
		output = "./Assets/fruta_2.xpm";
	else if (rand == 2)
		output = "./Assets/fruta_3.xpm";
	else if (rand == 3)
		output = "./Assets/fruta_4.xpm";
	else
		output = NULL;
	return (output);
}

char	*select_direction(t_player *player)
{
	char	*output;

	if (player->direction == 'D')
		output = "./Assets/mono_abajo.xpm";
	else if (player->direction == 'U')
		output = "./Assets/mono_arriba.xpm";
	else if (player->direction == 'R')
		output = "./Assets/mono_derecha.xpm";
	else if (player->direction == 'L')
		output = "./Assets/mono_izquierda.xpm";
	else
		output = NULL;
	return (output);
}

int	close_cross(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	ft_printf("Juego cerrado\n");
	exit(0);
}
