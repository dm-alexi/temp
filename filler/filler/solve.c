/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:58 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/11 19:44:26 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		score(t_map map, t_piece piece, int x, int y)
{
	int		i;
	int		score;
	int		connection;

	i = -1;
	connection = 0;
	score = 1;
	while (++i < piece.h * piece.w)
		if (piece.field[i] == '*')
		{
			if (y + i / piece.w < 0 || x + i % piece.w < 0 ||
			y + i / piece.w >= map.h || x + i % piece.w >= map.w ||
			ft_toupper(map.field[(y + i / piece.w) * map.w + x + i % piece.w])
			== map.enemy ||
			(ft_toupper(map.field[(y + i / piece.w) * map.w + x + i % piece.w])
			== map.mine && ++connection > 1))
				return (0);
			score += map.arr[(y + i / piece.w) * map.w + x + i % piece.w];
		}
	return (connection ? score : 0);
}

void	solve(t_map map, t_piece piece)
{
	int		smin;
	int		sc;
	t_point	k;
	t_point	t;

	smin = map.w * map.h * piece.h * piece.w;
	t.y = -piece.h;
	while (++t.y < map.h)
	{
		t.x = -piece.w;
		while (++t.x < map.w)
			if ((sc = score(map, piece, t.x, t.y)) && sc < smin)
			{
				smin = sc;
				k = t;
			}
	}
	ft_printf("%d %d\n", k.y, k.x);
}
