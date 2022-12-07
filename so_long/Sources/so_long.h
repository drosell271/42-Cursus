/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:57:26 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/07 18:37:29 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Extra/libft.h"
# include <mlx.h>

typedef struct map_data {
	char	**map;
	int		size_x;
	int		size_y;
}	t_map;

typedef struct player_data {
	int		pos_x;
	int		pos_y;
	char	direction;
	int		moves;
	int		objects_total;

}	t_player;

typedef struct s_data {
	void		*win;
	void		*mlx;
	void		*img;
	t_map		map;
	t_player	player;
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
GAME.C
+++++++++++++++++++
*/
void	player_init(t_player *player);
int		key_hook(int keycode, t_data *img);
int		move_player(t_data *img, char direction);
int		check_object(t_data *img, char direction);
char	obtain_object(t_data *img, char direction);

/*
+++++++++++++++++++
MAIN.C
+++++++++++++++++++
*/
int		check_input(int argc, char **argv);
int		main(int argc, char **argv);

/*
+++++++++++++++++++
MAPPING.C
+++++++++++++++++++
*/
int		get_size_y(char *input);
int		get_size_x(char *input);
char	**create_map(int size_x, int size_y);
char	**refill(int size_x, int size_y, char **output, char *input);
char	**generate_new_map(t_map *map, char	*input);

/*
+++++++++++++++++++
PRINT_MAP_1.C
+++++++++++++++++++
*/
void	print_map(t_map *map);
void	print_floor(t_data *img);
void	print_walls(t_data *img);
void	print_objects(t_data *img);
void	print_player(t_data *img);

/*
+++++++++++++++++++
PRINT_MAP_2.C
+++++++++++++++++++
*/
void	print_exit(t_data *img);

/*
+++++++++++++++++++
UTILS_1.C
+++++++++++++++++++
*/
size_t	ft_strlen_no_nl(const char *s);
char	*select_wall(int rand);
char	*select_object(int rand);
char	*select_direction(t_player *player);
int		close_cross(t_data *img);

/*
+++++++++++++++++++
UTILS_2.C
+++++++++++++++++++
*/
char	*select_exit(t_player *player);
int		render_frame(t_data *img);

#endif