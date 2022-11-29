/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:24:19 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/29 19:28:39 by drosell-         ###   ########.fr       */
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

char	*select_wall(int x)
{
	char	*output;

	if (rand == 0)
		output = "../Assets/wall_1.xpm";
	else if (rand == 1)
		output = "../Assets/wall_2.xpm";
	else if (rand == 2)
		output = "../Assets/wall_3.xpm";
	else if (rand == 3)
		output = "../Assets/wall_4.xpm";
	return (output);
}

char	*select_object(int x)
{
	char	*output;

	if (rand == 0)
		output = "../Assets/platano_1.xpm";
	else if (rand == 1)
		output = "../Assets/platano_2.xpm";
	else if (rand == 2)
		output = "../Assets/platano_3.xpm";
	else if (rand == 3)
		output = "../Assets/platano_4.xpm";
	return (output);
}

char	*select_other(char *temp)
{
	char	*output;

	if (temp == 'P')
		temp = "../Assets/player_abajo.xpm";
	else if (temp == 'E')
		temp = "../Assets/salida_pendiente.xpm";
	return (temp);
}
