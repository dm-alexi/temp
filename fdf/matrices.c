/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:52:19 by sscarecr          #+#    #+#             */
/*   Updated: 2020/01/20 20:08:50 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
/*
void			map_matrix_init(t_map *map)
{
	map->m
}
*/
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

t_vertex	*transform(t_vertex *v, double m[16], t_vertex *out)
{
	out->x = v->x * m[0] + v->y * m[1] + v->z * m[2] + v->w * m[3];
	out->y = v->x * m[4] + v->y * m[5] + v->z * m[6] + v->w * m[7];
	out->z = v->x * m[8] + v->y * m[9] + v->z * m[10] + v->w * m[11];
	out->w = v->x * m[12] + v->y * m[13] + v->z * m[14] + v->w * m[15];
	out->color = v->color;
	return (out);
}

double		*identity(void)
{
	static double m[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

	return (m);
}

double		*scale(int r)
{
	static double m[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

	m[0] = r;
	m[5] = r;
	m[10] = r;
	return (m);
}

double		*translation(double x, double y, double z)
{
	static double m[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

	m[3] = x;
	m[7] = y;
	m[11] = z;
	return (m);
}

double		*rotation(double ax, double ay, double az)
{
	static double m[16];
	static double rx[16] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	static double ry[16] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	static double rz[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

	rx[5] = cos(ax);
	rx[6] = -sin(ax);
	rx[9] = -rx[6];
	rx[10] = rx[5];
	ry[0] = cos(ay);
	ry[2] = sin(ay);
	ry[8] = -ry[2];
	ry[10] = ry[0];
	rz[0] = cos(az);
	rz[1] = -sin(az);
	rz[4] = -rz[1];
	rz[5] = rz[0];
	mult(rx, ry, m);
	//mult(rz, m, m);
	return (m);
}

double		*projection(double fov, double ratio, double near, double far)
{
	static double m[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0};

	m[0] = 1.0 / (tan(fov / 2) * ratio);
	m[5] = 1.0 / tan(fov / 2);
	m[10] = (near + far) / (near - far);
	m[11] = 2 * far * near / (near - far);
	return (m);
}
