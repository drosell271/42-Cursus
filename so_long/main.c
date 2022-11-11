/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:22:49 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/11 18:59:41 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

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
	if (check_input(argc, argv) != 1)
	{
		ft_printf("Error en los argumentos de entrada :(");
		return (0);
	}
	ft_printf("TODO OK :)");
	return (0);
}
