/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:50 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/11 22:59:51 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef _WIN32
# include <stdio.h>
#else
# include <unistd.h>
#endif
#include "filler.h"

int	get_player(t_map *map)
{
	char	*line;
	int		r;

	line = NULL;
	if ((r = get_next_line(STDIN_FILENO, &line)) < 0)
		return (sys_error());
	if (!r || !ft_strnequ(line, "$$$ exec p", 10) || line[10] < '1'
	|| line[10] > '2')
	{
		free(line);
		return (error("invalid player number\n"));
	}
	map->mine = (line[10] == '1' ? 'O' : 'X');
	map->enemy = (map->mine == 'O' ? 'X' : 'O');
	free(line);
	return (0);
}

int	get_dim(t_map *map)
{
	char	*line;
	char	*t;
	int		r;

	line = NULL;
	if ((r = get_next_line(STDIN_FILENO, &line)) < 0)
		return (sys_error());
	if (!r || !ft_strnequ(line, "Plateau ", 8) ||
	(map->h = ft_strtol(line + 8, &t, 10)) <= 0 ||
	(map->w = ft_atoi(t)) <= 0)
	{
		free(line);
		return (1);
	}
	free(line);
	if ((!map->field && !(map->field = (char*)malloc(map->h * map->w))) ||
	(!map->arr && !(map->arr = (int*)malloc(map->h * map->w * sizeof(int)))))
		return (sys_error());
	return (0);
}

int	get_map(t_map *map)
{
	char	*line;
	int		r;
	int		i;

	if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
		return (r ? sys_error() : error("invalid map\n"));
	free(line);
	i = -1;
	while (++i < map->h)
	{
		if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
			return (r ? sys_error() : error("invalid map\n"));
		ft_memcpy(map->field + map->w * i, ft_strchr(line, ' ') + 1, map->w);
		free(line);
	}
	return (setup(map));
}

int	get_piece(t_piece *piece)
{
	char	*line;
	char	*t;
	int		i;
	int		r;

	line = NULL;
	if ((r = get_next_line(STDIN_FILENO, &line)) <= 0 ||
	!ft_strnequ(line, "Piece ", 6) || (piece->h = ft_strtol(line + 6, &t, 10))
	<= 0 || (piece->w = ft_atoi(t)) <= 0)
	{
		free(line);
		return (r ? sys_error() : error("invalid piece\n"));
	}
	free(line);
	if (!(piece->field = (char*)malloc(piece->h * piece->w)))
		return (sys_error());
	i = -1;
	while (++i < piece->h)
	{
		if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
			return (r ? sys_error() : error("invalid piece\n"));
		ft_memcpy(piece->field + piece->w * i, line, piece->w);
		free(line);
	}
	return (0);
}
