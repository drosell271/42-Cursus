/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:54:10 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/09 14:33:18 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	int fd;

	if (check_input(argc, argv[2]) == 0)
		ft_printf("Hay un error en los parámmetros de entrada");
	fd = open(argv[2], O_RDONLY);
	if (fd == -1)
		ft_printf("El archivo no se pude abrir o no existe");
	else
		so_long(fd);
	return (0);
}