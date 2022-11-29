/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:57:26 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/29 18:19:12 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../../libft/libft.h"

/*
+++++++++++++++++++
PRINT_MSP.C
+++++++++++++++++++
*/
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/*
+++++++++++++++++++
CHECK_MAP.C
+++++++++++++++++++
*/
int		check_map_1(int size_x, int size_y, char **output);
int		check_map_2(int size_x, int size_y, char **output);
int		get_objects(int size_x, int size_y, char **output);
int		check_border(int size_x, int size_y, char **output);

/*
+++++++++++++++++++
UTILS_1.C
+++++++++++++++++++
*/
size_t	ft_strlen_no_nl(const char *s);

/*
+++++++++++++++++++
MAPPING
+++++++++++++++++++
*/
char	**generate_new_map(char	*input);
int		get_size_y(char *input);
int		get_size_x(char *input);
char	**create_map(int size_x, int size_y);
char	**refill(int size_x, int size_y, char **output, char *input);
char	**generate_new_map(char	*input);

/*
+++++++++++++++++++
MAIN
+++++++++++++++++++
*/
int		check_input(int argc, char **argv);
int		main(int argc, char **argv);

#endif