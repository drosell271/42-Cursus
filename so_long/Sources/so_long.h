/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:57:26 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/13 17:00:28 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Extra/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct search_data {
	int			id;
	int			level;
	int			distance;
	int			position_x;
	int			position_y;
	int			destination_x;
	int			destination_y;
	t_search	*previous;
	t_search	*next;
}	t_search;

typedef struct map_data {
	char	**map;
	int		size_x;
	int		size_y;
	int		player_x;
	int		player_y;
	int		target_number;
	int		*target_x;
	int		*target_y;
}	t_map;

typedef struct player_data {
	int		pos_x;
	int		pos_y;
	char	direction;
	int		moves;
	int		objects_total;
	int		total_movements;
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
void	clean_soround(t_data *img);

/*
+++++++++++++++++++
CHECK_PATH_1.C
+++++++++++++++++++
*/
void	check_path(t_map *map);
void	get_objects_coords(t_map *map);
void	get_num_objects(t_map *map);
void	get_player(t_map *map);
int		obtain_distance(int x_a, int y_a, int x_b, int y_b);

/*
+++++++++++++++++++
CHECK_PATH_2.C
+++++++++++++++++++
*/
int		search_path(t_map *map, t_search *search, int target);
int		main_search(t_search *search);

#endif