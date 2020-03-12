/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:24:32 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/12 22:47:05 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static int get_player(int fd, char *line, char **name)
{
	char	*t1;
	char	*t2;
	int		r;

	while ((r = get_next_line(fd, &line)) > 0 &&
	!ft_strnequ(line, "Plateau ", 8))
	{
		if (ft_strnequ(line, "$$$ exec p", 10) && (t1 = ft_strrchr(line, '/')) &&
		(t2 = ft_strrchr(line, '.')) && t2 > t1)
		{
			if (!(*name = ft_strsub(line, t1 - line + 1, t2 - t1 - 1)))
				sys_error();
			else
				return (1);
		}
		free(line);
	}
	if (r <= 0)
		r ? sys_error() : error("input error\n");
	return (0);
}

static void	get_initials(int fd, t_game *game)
{
	char	*line;
	char	*t;
	int		r;

	line = NULL;
	if (!get_player(fd, line, &game->p1))
		error("players not launched\n");
	if (get_player(fd, line, &game->p2) && (r = get_next_line(fd, &line)) <= 0)
		r ? sys_error() : error("map not received\n");
	if (!ft_strnequ(line, "Plateau ", 8) ||
	(game->h = ft_strtol(line + 8, &t, 10)) <= 0 ||
	(game->w = ft_atoi(t)) <= 0)
		error("invalid map\n");
	free(line);
}

static void	get_field(int fd, t_game *game)
{
	int	i;
	int	r;
	char	*line;
	
	if (!game->start)
		(game->start = (t_field*)ft_memalloc(sizeof(t_field))) ?
			(game->finish = game->start) : sys_error();
	else
	{
		if (!(game->finish->next = (t_field*)ft_memalloc(sizeof(t_field))))
			sys_error();
		game->finish->next->prev = game->finish;
		game->finish = game->finish->next;
	}
	if (!(game->finish->table = (char*)malloc(game->h * game->w)))
		sys_error();
	i = -1;
	while (++i < game->h)
	{
		if ((r = get_next_line(fd, &line)) <= 0)
			r ? sys_error() : error("invalid piece\n");
		ft_memcpy(game->finish->table + game->w * i, line, game->w);
		free(line);
	}
}

void		input(int fd, t_game *game)
{
	ft_bzero(game, sizeof(game));
	get_initials(fd, game);
	
}