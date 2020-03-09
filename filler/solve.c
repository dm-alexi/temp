/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:58 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/09 15:36:30 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		dist(t_map *map, int a, int b)
{
	return (ft_abs(a / map->w - b / map->w) + ft_abs(a % map->w - b % map->w));
}

int		get_center(t_map map, char c)
{
	int		i;
	int		x;
	int		y;
	int		n;

	i = 0;
	x = 0;
	y = 0;
	n = 0;
	while (i < map.w * map.h)
	{
		if (ft_toupper(map.field[i]) == c && ++n)
		{
			x += i % map.w;
			y += i / map.w;
		}
		++i;
	}
	if (n == 0)
		return (get_center(map, map.mine));
	return ((int)((double)y / n + 0.5) * map.w + (int)((double)x / n + 0.5));
}

int		possible(t_map map, t_piece piece, int x, int y)
{
	int		i;
	int		connection;

	i = -1;
	connection = 0;
	while (++i < piece.h * piece.w)
		if ((piece.field[i] == '*') &&
		(y + i / piece.w < 0 || x + i % piece.w < 0 ||
		y + i / piece.w >= map.h || x + i % piece.w >= map.w ||
		ft_toupper(map.field[(y + i / piece.w) * map.w + x + i % piece.w])
		== map.enemy ||
		(ft_toupper(map.field[(y + i / piece.w) * map.w + x + i % piece.w])
		== map.mine && ++connection > 1)))
			return (0);
	return (connection);
}

void	solve(t_map map, t_piece piece)
{
	int		x;
	int		y;
	int		center;
	int		len;
	t_point	k;

	len = map.w + map.h + 1;
	center = get_center(map, map.enemy);
	y = -piece.h;
	while (++y < map.h)
	{
		x = -piece.w;
		while (++x < map.w)
			if (possible(map, piece, x, y) && dist(&map, (y + piece.ycent)
			* map.w + x + piece.xcent, center) < len)
			{
				len = dist(&map, (y + piece.ycent) * map.w + x
					+ piece.xcent, center);
				k.x = x;
				k.y = y;
			}
	}
	ft_printf("%d %d\n", k.y, k.x);
}
