/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:01:13 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/09 16:23:57 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_input(int argc, char **argv)
{
	char	extension[4];
	int		counter;
	int		argv_lenght;

	if (argc != 2 || argv[2] == NULL)
		return (0);
	counter = 0;
	argv_lenght  = ft_printf(argv[2]);
	while (argv_lenght - counter >= argv_lenght - 4)
	{
		extension[4 - counter] = argv[2][argv_lenght - counter];
		counter++;
	}
	if (ft_strncmp(extension, ".ber", 4) != 1)
		return (1);
	return (0);
}