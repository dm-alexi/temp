/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:19:58 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/02 11:18:58 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void				fdf_init(char *file, t_map *map)
{
	if (!(map->mlx = mlx_init()) ||
		!(map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, file)) ||
		!(map->image = new_image(map->mlx, WIDTH, HEIGHT)))
		sys_error();
	mlx_hook(map->win, 2, 1L << 0, &key_handle, map);
	mlx_hook(map->win, 4, 1L << 2, &mouse_handle, map);
	mlx_hook(map->win, 17, 1L << 17, &win_close, map);
	matrix_init(map);
	mlx_loop(map->mlx);
}

/*
** Vertex transformation; "w"-field used to store original "z" value
** for color (gradient) calculation.
*/

static t_vertex		*transform(t_vertex *v, double m[16], t_vertex *out)
{
	out->x = v->x * m[0] + v->y * m[1] + v->z * m[2] + v->w * m[3];
	out->y = v->x * m[4] + v->y * m[5] + v->z * m[6] + v->w * m[7];
	out->z = v->x * m[8] + v->y * m[9] + v->z * m[10] + v->w * m[11];
	out->w = v->z;
	out->color = v->color;
	return (out);
}

static void			matrix_set(t_map *map)
{
	ft_bzero(&map->matrix.result, 16 * sizeof(double));
	map->matrix.result[0] = 1;
	map->matrix.result[5] = 1;
	map->matrix.result[10] = 1;
	map->matrix.result[15] = 1;
	map->matrix.result[3] = -map->columns / 2;
	map->matrix.result[7] = -map->rows / 2;
	map->matrix.result[11] = -(map->z_max + map->z_min) / 2;
}

void				matrix_result(t_map *map)
{
	int		i;

	matrix_set(map);
	mult(scale(map->matrix.scale), map->matrix.result, map->matrix.result);
	mult(rotation(map->matrix.rotate), map->matrix.result, map->matrix.result);
	mult(translation(map->matrix.move), map->matrix.result, map->matrix.result);
	i = -1;
	while (++i < map->length)
		transform(map->grid + i, map->matrix.result, map->show + i);
	ft_bzero(map->image->s,
		map->image->width * map->image->height * map->image->bpp / 8);
	i = -1;
	while (++i < map->length)
	{
		if (i % map->columns < map->columns - 1 &&
		check_line(map->image, map->show + i, map->show + i + 1))
				image_draw_line(map->image, map->show + i, map->show + i + 1);
		if (i < map->length - map->columns &&
		check_line(map->image, map->show + i, map->show + i + 1))
			image_draw_line(map->image, map->show + i,
			map->show + i + map->columns);
	}
	mlx_put_image_to_window(map->mlx, map->win, map->image->img, 0, 0);
	ft_menu(map);
}

void				matrix_init(t_map *map)
{
	double	scale;

	scale = (((double)map->image->width / map->columns <
		(double)map->image->height / map->rows) ? map->image->width
		/ map->columns : map->image->height / map->rows) * 0.7;
	map->matrix.rotate[0] = 0;
	map->matrix.rotate[1] = 0;
	map->matrix.rotate[2] = 0;
	map->matrix.move[0] = WIDTH / 2;
	map->matrix.move[1] = HEIGHT / 2;
	map->matrix.move[2] = 0;
	map->matrix.scale[0] = scale;
	map->matrix.scale[1] = scale;
	map->matrix.scale[2] = scale;
	matrix_result(map);
}
