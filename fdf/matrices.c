/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:52:19 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/27 21:53:43 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

double		*mult(double a[16], double b[16], double c[16])
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			c[i * 4 + j] = 0.0;
			k = -1;
			while (++k < 4)
				c[i * 4 + j] += a[i * 4 + k] * b[k * 4 + j];
		}
	}
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

double		*projection(double fov, double ratio, double near, double far)
{
	static double m[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0};

	m[0] = 1.0 / (tan(fov / 2) * ratio);
	m[5] = 1.0 / tan(fov / 2);
	m[10] = (near + far) / (near - far);
	m[11] = 2 * far * near / (near - far);
	return (m);
}
