/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:31:00 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/13 23:07:32 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fractol.h"
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

static void	key_move(int key, void *param)
{
	t_screen	*s;
	double		sizex;
	double		sizey;

	s = param;
	sizex = s->maxx - s->minx;
	sizey = s->maxy - s->miny;
	if (key == UP || key == DOWN)
	{
		s->miny += key == UP ? MOVE_SPEED * sizey : -MOVE_SPEED * sizey;
		s->maxy += key == UP ? MOVE_SPEED * sizey : -MOVE_SPEED * sizey;
	}
	else if (key == LEFT || key == RIGHT)
	{
		s->minx += key == LEFT ? MOVE_SPEED * sizex : -MOVE_SPEED * sizex;
		s->maxx += key == LEFT ? MOVE_SPEED * sizex : -MOVE_SPEED * sizex;
	}
}

int			key_handle(int key, void *param)
{
	t_screen	*s;

	s = param;
	if (key == ESC)
		exit(EXIT_SUCCESS);
	else if (key == SPACE)
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
	threads(s);
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	t_screen	*s;

	s = param;
	if (!s->cblock)
	{
		if (x >= 0 && y >= 0 && x < s->image->width && y < s->image->height)
			map_coord(&s->c, s, x, y);
		else
		{
			s->c.re = JULIA_RE;
			s->c.im = JULIA_IM;
		}
		threads(s);
	}
	return (0);
}

static void	zoom(int key, int x, int y, t_screen *s)
{
	double		wx;
	double		wy;
	double		zoom;

	zoom = (key == SCROLL_UP ? ZOOM_FACTOR : 1.0 / ZOOM_FACTOR);
	wx = s->minx + x * (s->maxx - s->minx) / s->image->width;
	wy = s->miny + y * (s->maxy - s->miny) / s->image->height;
	s->minx = wx + (s->minx - wx) * zoom;
	s->miny = wy + (s->miny - wy) * zoom;
	s->maxx = wx + (s->maxx - wx) * zoom;
	s->maxy = wy + (s->maxy - wy) * zoom;
}

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
