/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:31:00 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/14 19:46:33 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "visual.h"
#define ESC 53
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define PGDN 121
#define PGUP 116
#define END 119
#define HOME 115

#define STEP 10

static void	delete_game(t_game *game)
{
	t_field	*t;

	while (game->start)
	{
		t = game->start->next;
		free(game->start->table);
		free(game->start);
		game->start = t;
	}
	free(game->p1);
	free(game->p2);
	free(game->title);
}

int			win_close(void *param)
{
	t_screen	*s;
	t_game		*game;

	game = param;
	s = game->screen;
	mlx_destroy_window(s->mlx, s->win);
	mlx_destroy_image(s->mlx, s->image->img);
	free(s->image);
	free(s);
	delete_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

int			key_handle(int key, void *param)
{
	t_game		*game;
	int			i;

	i = 0;
	game = param;
	if (key == ESC)
		win_close(param);
	else if (key == RIGHT && game->current->next)
		game->current = game->current->next;
	else if (key == LEFT && game->current->prev)
		game->current = game->current->prev;
	else if (key == UP || key == HOME)
		game->current = game->start;
	else if (key == DOWN || key == END)
		game->current = game->finish;
	else if (key == PGUP)
		while (i++ < STEP && game->current->prev)
			game->current = game->current->prev;
	else if (key == PGDN)
		while (i++ < STEP && game->current->next)
			game->current = game->current->next;
	draw(game);
	return (0);
}
