/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:27:21 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/16 21:08:20 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_put_pixel(t_image *image, int x, int y, int color)
{
	int		i;

	i = x * image->bpp / 8 + y * image->sizeline;
	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ;
	if (image->endian)
	{
		if (image->bpp > 24)
			image->map[i++] = 0;
		image->map[i++] = color >> 16;
		image->map[i++] = color >> 8;
		image->map[i] = color;
	}
	else
	{
		image->map[i++] = color;
		image->map[i++] = color >> 8;
		image->map[i++] = color >> 16;
		if (image->bpp > 24)
			image->map[i] = 0;
	}
}
/*
void	image_draw_line(t_image *image, t_dot *a, t_dot *b, int color)
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
}*/