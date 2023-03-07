/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:33:03 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/09 15:30:58 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_exit(t_data *img)
{
	int	width;
	int	height;
	int	x;
	int	y;

	y = -1;
	while (++y < img->map.size_y)
	{
		x = -1;
		while (++x <= img->map.size_x)
		{
			if (img->map.map[y][x] == 'E' )
			{	
				img->img = mlx_xpm_file_to_image(img->mlx,
						select_exit(&img->player), &width, &height);
				mlx_put_image_to_window(
					img->mlx, img->win, img->img, x * 64, y * 64);
				mlx_destroy_image(img->mlx, img->img);
			}
		}
	}
}
