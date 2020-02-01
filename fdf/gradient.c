/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:42:42 by stristim          #+#    #+#             */
/*   Updated: 2020/02/01 21:30:15 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** (color >> 16) & 0xFF - red channel
** (color >> 8) & 0xFF - green channel
** (color & 0xFF) - blue channel
*/

int		gradient(int start, int finish, double k)
{
	int		r;
	int		g;
	int		b;
	int		color;

	r = ((start >> 16) & 0xFF) * (1 - k) + ((finish >> 16) & 0xFF) * k + 0.5;
	g = ((start >> 8) & 0xFF) * (1 - k) + ((finish >> 8) & 0xFF) * k + 0.5;
	b = (start & 0xFF) * (1 - k) + (finish & 0xFF) * k + 0.5;
	color = (r << 16) | (g << 8) | b;
	return (color);
}

int		gradient_check(t_vertex *a, t_vertex *b, int steps, int i)
{
	double	length;
	double	k;
	int		color;

	k = (double)i / steps;
	length = ft_abs(a->w) + ft_abs(b->w);
	if ((a->w >= 0 && b->w >= 0) || (a->w <= 0 && b->w <= 0))
		color = gradient(a->color, b->color, k);
	else if (a->w < 0)
		color = k < (length - b->w) / length ? gradient(a->color, WHITE, k) :
			gradient(WHITE, b->color, k);
	else
		color = k > (length - a->w) / length ? gradient(a->color, WHITE, k) :
			gradient(WHITE, b->color, k);
	return (color);
}

void	set_colors(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->length)
		if (map->grid[i].z == 0)
			map->grid[i].color = map->midcolor;
		else if (map->grid[i].z > 0)
			map->grid[i].color = gradient(map->midcolor, map->maxcolor,
				(double)map->grid[i].z / map->z_max);
		else
			map->grid[i].color = gradient(map->midcolor, map->mincolor,
				(double)map->grid[i].z / map->z_min);
}
