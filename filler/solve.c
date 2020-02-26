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

void	solve(t_map map, t_piece piece)
{
    int		i;
    int		center;
    int		len;
    int		k;

    len = map.w * map.h;
	center = get_center(map, map.enemy);
	i = -(piece.h - 1) * map.w - (piece.w - 1);
	while (i < map.h * map.w)
	{
		//if (possible(map, i)) //&& dist(map, i, center) < len &&
		++i;
	}
}
