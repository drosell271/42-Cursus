/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:45:29 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/09 14:40:42 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "ft_printf.h"
#include "get_next_line.h"

//map_to_array.c
char **map_to_array(int fd);

//map_check.c

//so_long.c
void so_long(int fd);

//so_long_utils.c
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int main(int argc, char *argv[]);

//main.c
int main(int argc, char *argv[]);

#endif