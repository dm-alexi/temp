/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:50 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/11 19:39:33 by sscarecr         ###   ########.fr       */
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
	int		r;

	if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
		r ? sys_error() : error("player number not received\n");
	if (!ft_strnequ(line, "$$$ exec p", 10) || line[10] < '1' || line[10] > '2')
		error("invalid player number\n");
	map->mine = (line[10] == '1' ? 'O' : 'X');
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
	if ((!map->field && !(map->field = (char*)malloc(map->h * map->w))) ||
	(!map->arr && !(map->arr = (int*)malloc(map->h * map->w * sizeof(int)))))
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
		ft_memcpy(map->field + map->w * i, ft_strchr(line, ' ') + 1, map->w);
		free(line);
	}
	setup(map);
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
		ft_memcpy(piece->field + piece->w * i, line, piece->w);
		free(line);
	}
}
