/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:50 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/04 17:20:49 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef _WIN32
# include <stdio.h>
#else
# include <unistd.h>
#endif
#include "filler.h"

void		get_player(t_map *map)
{
	char	*line;
	char	*s;
	int		r;

	if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
		r ? sys_error() : error("player number not received\n");
	if ((s = ft_strchr(line, 'p')))
		map->mine = (*(s + 1) == '1' ? 'O' : 'X');
	else
		error("invalid player number\n");
	map->enemy = (map->mine == 'O' ? 'X' : 'O');
	free(line);
}

int			get_dim(t_map *map)
{
	char	*line;
	char	*t;
	int		r;

	if ((r = get_next_line(STDIN_FILENO, &line)) < 0)
		sys_error();
	if (!r)
		return (0);
	if ((map->h = ft_strtol(line + 8, &t, 10)) <= 0 ||
		(map->w = ft_atoi(t)) <= 0)
			error("invalid map size\n");
	free(line);
	if (!map->field && !(map->field = (char*)malloc(map->h * map->w)))
		sys_error();
	return (1);
}

void		get_map(t_map *map)
{
	char	*line;
	int		r;
	int		i;

	if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
		r ? sys_error() : error("invalid map\n");
	free(line);
	i = -1;
	while (++i < map->h)
	{
		if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
			r ? sys_error() : error("invalid map\n");
		ft_strncpy(map->field + map->w * i, ft_strchr(line, ' ') + 1, map->w);
		free(line);
	}
}

static void	get_piece_center(t_piece *piece)
{
	int		i;
	int		x;
	int		y;
	int		n;

	i = 0;
	x = 0;
	y = 0;
	n = 0;
	while (i < piece->w * piece->h)
	{
		if (piece->field[i] == '*' && ++n)
		{
			x += i % piece->w;
			y += i / piece->w;
		}
		++i;
	}
	piece->ycent = (double)y / n + 0.5;
	piece->xcent = (double)x / n + 0.5;
}

void		get_piece(t_piece *piece)
{
	char	*line;
	char	*t;
	int		i;
	int		r;

	if ((r = get_next_line(STDIN_FILENO, &line)) < 0)
		sys_error();
	if (!r || !ft_strnequ(line, "Piece ", 6))
		error("piece not received\n");
	if ((piece->h = ft_strtol(line + 6, &t, 10)) <= 0 ||
		(piece->w = ft_atoi(t)) <= 0)
		error("invalid piece size\n");
	free(line);
	if (!piece->field && !(piece->field = (char*)malloc(piece->h * piece->w)))
		sys_error();
	i = -1;
	while (++i < piece->h)
	{
		if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
			r ? sys_error() : error("invalid piece\n");
		ft_strncpy(piece->field + piece->w * i, line, piece->w);
		free(line);
	}
	get_piece_center(piece);
}
