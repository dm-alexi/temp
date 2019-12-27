/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:19:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/27 21:55:28 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include "fdf.h"

void	fill_image(void *img)
{
	int		bpp;
	int		sl;
	int		endian;
	char 	*s;

	s = mlx_get_data_addr(img, &bpp, &sl, &endian);
	ft_printf("%d %d %d", bpp, sl, endian);
	s[100 * bpp / 8 + 10 * sl] = 122;
	s[100 * bpp / 8 + 10 * sl + 1] = 122;
	s[100 * bpp / 8 + 10 * sl + 2] = 122;
	s[100 * bpp / 8 + 10 * sl + 3] = 0;
}

void	window(char *file, t_map *map)
{
	void		*mlx;
	void		*win;
	t_image		*image;

	/*if (!(mlx = mlx_init()) || !(win = mlx_new_window(mlx, WIDTH, HEIGHT, file))
	|| !(img = mlx_new_image(mlx, WIDTH, HEIGHT)))
		sys_error();*/
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, file);
	image = new_image(mlx, WIDTH, HEIGHT);
	mlx_key_hook(win, &key_handle, NULL);
	t_vertex *shown = (t_vertex*)malloc(sizeof(t_vertex) * map->length);
	double *m = (double*)malloc(sizeof(double) * 16);
	//m = projection(1.57, 0.25, 0.1, 20);
	//m = identity();
	//m = scale(50);
	mult(scale(50), projection(1.57, 1, 0.5, 20), m);
	for (int i = 0; i < map->length; ++i)
	{
		transform(map->grid + i, m, shown + i);
		//image_put_pixel(image, shown[i].x + 600, shown[i].y + 200, shown[i].z ? 0xff0000 : shown[i].color);
		
	}
	for (int i = 0; i < map->length; ++i)
	{
		//transform(map->grid + i, m, shown + i);
		//image_put_pixel(image, shown[i].x + 600, shown[i].y + 200, shown[i].z ? 0xff0000 : shown[i].color);
		if (i % map->columns < map->columns - 1)
			image_draw_line(image, shown + i, shown + i + 1);
		if (i <= map->length - map->columns)
			image_draw_line(image, shown + i, shown + i + map->columns);
	}
	//image_draw_line(image, shown, shown + 1);
	//image_draw_line(image, shown + 1, shown + 2);
	mlx_put_image_to_window(mlx, win, image->img, 0, 0);
	mlx_loop(mlx);
}
