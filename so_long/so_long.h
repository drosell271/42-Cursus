/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:45:29 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/11 14:58:13 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include "../libft/libft.h"

//checks.c
int check_input(int argc, char **argv);
int check_map(char **map);

//so_long.c
char **so_long(char *argv);

//map_generator.c
char	**file_2_map(char *argv);
int 	y_size_calculator(char *argv);
int		x_size_calculator(char *argv);
void	**map_generator(int y_size, char **map);
void	map_filler(char **map, char *argv);

#endif