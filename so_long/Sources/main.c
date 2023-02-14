/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:22:49 by drosell-          #+#    #+#             */
/*   Updated: 2023/02/14 17:49:54 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(int argc, char **argv)
{
	char	extension[5];
	int		size;
	int		counter;

	if (argc != 2 || argv == NULL)
		return (0);
	size = ft_strlen (argv[1]);
	counter = 0;
	if (size >= 6)
	{
		while (size - counter >= size - 4)
		{
			extension[4 - counter] = argv[1][size - counter];
			counter ++;
		}
		if (ft_strncmp(extension, ".ber", 4) == 0)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (check_input(argc, argv) != 1)
	{
		ft_printf("ERROR EN EL ARGUMENTO DE ENTRADA :(\n");
		return (0);
	}
	ft_printf("Argumentos correctos\n");
	map.map = generate_new_map(&map, argv[1]);
	if (check_path(&map) == -1)
	{
		ft_printf("ERROR, NO EXISTE CAMINO\n");
		return (0);
	}
	print_map(&map);
	return (0);
}
