/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:44:17 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/01 16:39:38 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static t_vertex		make_vertex(int x, int y, int z, int color)
{
	t_vertex	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.color = color;
	return (v);
}

static void			image_put_pixel(t_image *image, t_vertex v)
{
	int		i;

	i = v.x * image->bpp / 8 + v.y * image->sizeline;
	if (v.x < 0 || v.y < 0 || v.x >= image->width || v.y >= image->height ||
	(*(int*)(image->s + i) != 0 && image->zbuf[v.y * image->width + v.x] > v.z))
		return ;
	if (image->endian)
	{
		if (image->bpp > 24)
			image->s[i++] = 0;
		image->s[i++] = v.color >> 16;
		image->s[i++] = v.color >> 8;
		image->s[i] = v.color;
	}
	else
	{
		image->s[i++] = v.color;
		image->s[i++] = v.color >> 8;
		image->s[i++] = v.color >> 16;
		if (image->bpp > 24)
			image->s[i] = 0;
	}
	image->zbuf[v.y * image->width + v.x] = v.z;
}

void				image_draw_line(t_image *image, t_vertex *a, t_vertex *b)
{
	double	step;
	double	z_step;
	int		i;

	i = -1;
	step = b->x - a->x >= ft_abs(b->y - a->y) ?
		(double)(a->y - b->y) / (a->x - b->x) :
		(double)(a->x - b->x) / (a->y - b->y);
	z_step = (double)(a->z - b->z) / (b->x - a->x >= ft_abs(b->y - a->y) ?
		a->x - b->x : a->y - b->y);
	if (a->x == b->x && a->y == b->y)
		image_put_pixel(image, make_vertex(a->x, a->y, a->z > b->z ? a->z : 
			b->z, a->z > b->z ? a->color : b->color));
	else if ((a->x >= b->x && a->y >= b->y) || 
	a->x - b->x > ft_abs(b->y - a->y) || a->y - b->y > ft_abs(b->x - a->x))
		image_draw_line(image, b, a);
	else if (b->x - a->x >= ft_abs(b->y - a->y))
		while (++i < b->x - a->x)
			image_put_pixel(image, make_vertex(a->x + i, a->y + i * step,
				a->z + z_step * i, gradient_check(a, b, b->x - a->x, i)));
	else
		while (++i <= b->y - a->y)
			image_put_pixel(image, make_vertex(a->x + i * step, a->y + i,
				a->z + z_step * i, gradient_check(a, b, b->y - a->y, i)));
}
