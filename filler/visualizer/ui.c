/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:31:00 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/14 15:29:08 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "visual.h"
#define ESC 53
#define MOUSE1 1
#define MOUSE2 2
#define SCROLL_UP 4
#define SCROLL_DN 5
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define SPACE 49
#define NUM_PLUS 69
#define PLUS 24
#define NUM_MINUS 78
#define MINUS 27

#define MOVE_SPEED 0.05
#define ZOOM_FACTOR 1.1

int		win_close(void *param)
{
	t_screen	*s;
	t_game		*game;

	game = param;
	s = game->screen;
	mlx_destroy_window(s->mlx, s->win);
	mlx_destroy_image(s->mlx, s->image->img);
	mlx_destroy_image(s->mlx, s->menu->img);
	free(s->image);
	free(s->menu);
	free(s);
	delete_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

int		key_handle(int key, void *param)
{
	t_game	*game;

	game = param;
	if (key == ESC)
		win_close(param);
	else if (key == RIGHT && game->current->next)
		game->current = game->current->next;
	else if (key == LEFT && game->current->prev)
		game->current = game->current->prev;
	/*else if (key == SPACE)
		++s->gamma;
	else if (key == PLUS || key == NUM_PLUS)
		s->maxiter += 8;
	else if ((key == MINUS || key == NUM_MINUS) && s->maxiter > 8)
		s->maxiter -= 8;
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		key_move(key, param);
	else if (key == Q)
		reset(s);
	else if (key == A)
		++s->degree;
	else if (key == Z && s->degree > 2)
		--s->degree;
		*/
	draw_map(game);
	return (0);
}

/*
int			mouse_handle(int key, int x, int y, void *param)
{
	t_screen	*s;

	s = param;
	if (x >= 0 && y >= 0 && x < s->image->width && y < s->image->height)
	{
		if (key == SCROLL_UP || key == SCROLL_DN)
		{
			zoom(key, x, y, s);
			if (key == SCROLL_UP && s->maxiter > 8)
				s->maxiter -= 8;
			else if (key == SCROLL_DN)
				s->maxiter += 8;
		}
		else if (key == MOUSE1)
			s->cblock = !s->cblock;
	}
	threads(s);
	return (0);
}
*/
