/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:33:03 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/29 18:01:57 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
//#include "so_long.h"

typedef struct s_data {
	void	*img;
	void	*win;
	void	*mlx;
}	t_data;

print_floor(t_data img, int w);

int	main(void)
{
	t_data	img;
	int		img_width;
	int		img_height;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1560, 784, "So_Long");
	print_floor(img, );
	print_walls();
	print_objects();
	/*img.img = mlx_xpm_file_to_image(img.mlx, "../Assets/platano_1.xpm", &img_width, &img_height);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);*/
	mlx_loop(img.mlx);
}

