/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:57:56 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/23 17:32:07 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	init_julia(t_screen *s)
{
	s->minx = -2.0;
	s->miny = -2.0;
	s->maxx = 2.0;
	s->maxy = 2.0;
	s->c.re = JULIA_RE;
	s->c.im = JULIA_IM;
	mlx_hook(s->win, 6, 1L << 6, &mouse_move, s);
}

void	init_mandelbrot(t_screen *s)
{
	s->minx = -2.5;
	s->miny = -1.75;
	s->maxx = 1.0;
	s->maxy = 1.75;
}

int	init(void *mlx, void *func(void*), char *name)
{
	t_screen	*screen;

	if (!(screen = (t_screen*)ft_memalloc(sizeof(t_screen))) ||
	!(screen->win = mlx_new_window(mlx, WIDTH, HEIGHT, name)) ||
	!(screen->image = new_image(mlx, WIDTH, HEIGHT)))
		sys_error();
	screen->mlx = mlx;
	screen->maxiter = INIT_ITER;
	screen->func = func;
	if (func == julia)
		init_julia(screen);
	else if (func == mandelbrot)
		init_mandelbrot(screen);
	mlx_hook(screen->win, 2, 1L << 0, &key_handle, screen);
	mlx_hook(screen->win, 4, 1L << 2, &mouse_handle, screen);
	mlx_hook(screen->win, 17, 1L << 17, &win_close, screen);
	threads(screen);
	return (1);
}
