/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:19:58 by sscarecr          #+#    #+#             */
/*   Updated: 2020/01/13 22:34:19 by sscarecr         ###   ########.fr       */
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
	mlx_hook(win, 17, 1L << 17, &win_close, NULL);
	t_vertex *shown = (t_vertex*)malloc(sizeof(t_vertex) * map->length);
	double *m = (double*)malloc(sizeof(double) * 16);
	//m = projection(1.57, 0.25, 0.1, 20);
	m = identity();
	//m = scale(50);
	//mult(translation(100, 100, 0), identity(), m);
	mult(translation(-map->columns / 2, -map->rows / 2, 0), m, m);
	mult(scale(50), m, m);
	mult(translation(WIDTH / 2, HEIGHT / 2, 0), m, m);
	
	for (int i = 0; i < map->length; ++i)
	{
		transform(map->grid + i, m, shown + i);
		
	}
	for (int i = 0; i < map->length; ++i)
	{
		if (i % map->columns < map->columns - 1)
			image_draw_line(image, shown + i, shown + i + 1);
		if (i < map->length - map->columns)
			image_draw_line(image, shown + i, shown + i + map->columns);
	}
	mlx_put_image_to_window(mlx, win, image->img, 0, 0);
	mlx_loop(mlx);
}
