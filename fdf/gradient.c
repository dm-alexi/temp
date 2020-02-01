/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:42:42 by stristim          #+#    #+#             */
/*   Updated: 2020/02/01 21:01:39 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int red (int color)
{
    return (color >> 16) & 0xFF;
}

int green(int color)
{
    return (color >> 8) & 0xFF;
}

int blue(int color)
{
    return (color & 0xFF);
}

/*
** (color >> 16) & 0xFF - red channel
** (color >> 8) & 0xFF - green channel
** (color & 0xFF) - blue channel
*/

int     gradient(int start, int finish, double k)
{
    int     stepR;
    int     stepG;
    int     stepB;
    int     color;

    stepR = red(start) + (red(finish) - red(start))*k + 0.5;
    stepG = green(start) + (green(finish) - green(start))*k  + 0.5;
    stepB = blue(start) + (blue(finish) - blue(start))*k + 0.5;
    color = (stepR << 16) | (stepG << 8) | stepB;
    return (color);
}

int     gradient_check(t_vertex *a, t_vertex *b, int steps, int i)
{
    double  length;
    double  k;
    int     color;

    k = (double)i / steps;
    length = ft_abs(a->w) + ft_abs(b->w);
    if ((a->w >= 0 && b->w >= 0) || (a->w <= 0 && b->w <= 0))
        color = gradient(a->color, b->color, k);
    else if (a->w < 0)
        color = k < (length - b->w) / length ? gradient(a->color, MIDCOLOR, k) :
            gradient(MIDCOLOR, b->color, k);
    else
        color = k > (length - a->w) / length ? gradient(a->color, MIDCOLOR, k) :
            gradient(MIDCOLOR, b->color, k);
    return (color);
}

void		set_colors(t_map *map)
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

void		put_colors(t_map *map)
{
	map->midcolor = MIDCOLOR;
	if (map->mincolor == MINCOLOR1)
	{
		map->mincolor = MINCOLOR2;
		map->maxcolor = MAXCOLOR2;
	}
	else if (map->mincolor == MINCOLOR2)
	{
		map->mincolor = MINCOLOR3;
		map->maxcolor = MAXCOLOR3;
	}
	else
	{
		map->mincolor = MINCOLOR1;
		map->maxcolor = MAXCOLOR1;
	}
}