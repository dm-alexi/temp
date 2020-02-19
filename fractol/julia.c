/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:27:55 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/19 22:55:46 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <pthread.h>
#include "fractol.h"

void	map_coord(t_complex *z, t_screen *s, int x, int y)
{
	z->re = (4.0 * x / s->image->width - 2.0) / s->zoom + s->moveX;
	z->im = (4.0 * y / s->image->height - 2.0) / s->zoom + s->moveY;
}

void	*julia_inst(void *param)
{
	t_thread	*t;
	t_complex	z;
	int			x;
	int			i;

	t = param;
	while (t->start != t->finish)
	{
		x = -1;
		while (++x < t->s->image->width)
		{
			map_coord(&z, t->s, x, t->start);
			i = 0;
			while (i < t->s->maxiter && square_dist(&z, t->s->c) <= 4)
				++i;
			image_put_pixel(t->s->image, x, t->start, get_color(i, t->s->maxiter,
				t->s->gamma));
		}
		++t->start;
	}
	return (NULL);
}

void	*julia(void *param)
{
	t_screen	*s;
	t_complex	z;
	int			x;
	int			y;
	int			i;
	pthread_t	t[4];

	s = param;
	y = -1;
	while (++y < s->image->height)
	{
		x = -1;
		while (++x < s->image->width)
		{
			map_coord(&z, s, x, y);
			i = 0;
			while (i < s->maxiter && square_dist(&z, s->c) <= 4)
				++i;
			image_put_pixel(s->image, x, y, get_color(i, s->maxiter, s->gamma));
		}
	}
	mlx_put_image_to_window(s->mlx, s->win, s->image->img, 0, 0);
	return (NULL);
}
