/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:57:26 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/15 18:42:59 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"

/*
+++++++++++++++++++
MAPPING
+++++++++++++++++++
*/
char	**generate_new_map(char	*input);
int		get_size_y(char *input);
int		get_size_x(char *input);
void	create_map(int size_x, int size_y, char **output);
void	refill(char **output, char *input);
char	**generate_new_map(char	*input);

/*
+++++++++++++++++++
MAIN
+++++++++++++++++++
*/
int		check_input(int argc, char **argv);
int		main(int argc, char **argv);

#endif