/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:52:19 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/01 16:30:47 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf.h"

double		*mult(double a[16], double b[16], double c[16])
{
	int		i;
	int		j;
	int		k;
	double	d[16];

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			d[i * 4 + j] = 0.0;
			k = -1;
			while (++k < 4)
				d[i * 4 + j] += a[i * 4 + k] * b[k * 4 + j];
		}
	}
	i = -1;
	while (++i < 16)
		c[i] = d[i];
	return (c);
}

static void		identity(double m[16])
{
	ft_bzero(m, 16 * sizeof(double));
	m[0] = 1;
	m[5] = 1;
	m[10] = 1;
	m[15] = 1;
}

static double		*scale(double r)
{
	static double	m[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

	m[0] = r;
	m[5] = r;
	m[10] = r;
	return (m);
}

double		*rotation(double r[3])
{
	static double m[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	static double rx[16] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	static double ry[16] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	static double rz[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

	rx[5] = cos(r[0]);
	rx[6] = -sin(r[0]);
	rx[9] = -rx[6];
	rx[10] = rx[5];
	ry[0] = cos(r[1]);
	ry[2] = sin(r[1]);
	ry[8] = -ry[2];
	ry[10] = ry[0];
	rz[0] = cos(r[2]);
	rz[1] = -sin(r[2]);
	rz[4] = -rz[1];
	rz[5] = rz[0];
	mult(ry, rx, m);
	mult(rz, m, m);
	return (m);
}

static double		*center()
{
	static double	m[16] = {1, 0, 0, WIDTH / 2, 0, 1, 0, HEIGHT / 2, 0, 0, 1, 0, 0, 0, 0, 1};

	return (m);
}

static double		*translation(double move[3])
{
	static double	m[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

	m[3] = move[0];
	m[7] = move[1];
	m[11] = move[2];
	return (m);
}

static void		translate(double m[16], double x, double y, double z)
{
	identity(m);
	m[3] = x;
	m[7] = y;
	m[11] = z;
}

void			matrix_result(t_map *map)
{
	int		i;

	translate(map->matrix.initial, -map->columns / 2, -map->rows / 2, -(map->z_max + map->z_min) / 2);
	mult(scale(map->matrix.scale), map->matrix.initial, map->matrix.result);
	mult(rotation(map->matrix.rotate), map->matrix.result, map->matrix.result);
	mult(center(), map->matrix.result, map->matrix.result);
	mult(translation(map->matrix.move), map->matrix.result, map->matrix.result);
	i = -1;
	while (++i < map->length)
		transform(map->grid + i, map->matrix.result, map->show + i);
	ft_bzero(map->image->s, map->image->width * map->image->height * map->image->bpp / 8);
	i = -1;
	while (++i < map->length)
	{
		if (i % map->columns < map->columns - 1)
			image_draw_line(map->image, map->show + i, map->show + i + 1);
		if (i < map->length - map->columns)
			image_draw_line(map->image, map->show + i, map->show + i + map->columns);
	}
	mlx_put_image_to_window(map->mlx, map->win, map->image->img, 0, 0);
	ft_menu(map);
}

void			matrix_init(t_map *map)
{
	if ((double)map->image->width / map->columns <
		(double)map->image->height / map->rows)
		map->matrix.scale = map->image->width / map->columns * 0.5;
	else
		map->matrix.scale = map->image->height / map->rows * 0.5;
	map->matrix.rotate[0] = 0;
	map->matrix.rotate[1] = 0;
	map->matrix.rotate[2] = 0;
	map->matrix.move[0] = 0;
	map->matrix.move[1] = 0;
	map->matrix.move[2] = 0;
	matrix_result(map);
}

t_vertex	*transform(t_vertex *v, double m[16], t_vertex *out)
{
	out->x = v->x * m[0] + v->y * m[1] + v->z * m[2] + v->w * m[3];
	out->y = v->x * m[4] + v->y * m[5] + v->z * m[6] + v->w * m[7];
	out->z = v->x * m[8] + v->y * m[9] + v->z * m[10] + v->w * m[11];
	out->w = v->z;
	out->color = v->color;
	return (out);
}
