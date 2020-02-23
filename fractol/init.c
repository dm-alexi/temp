/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:57:56 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/23 20:21:18 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	init_julia(t_screen *s)
{
	s->func = julia;
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
	s->func = mandelbrot;
	s->minx = -2.0;
	s->miny = -2.0;
	s->maxx = 2.0;
	s->maxy = 2.0;
}

void	init_burning(t_screen *s)
{
	s->func = burning;
	s->minx = -2.0;
	s->miny = -2.0;
	s->maxx = 2.0;
	s->maxy = 2.0;
}

void	init_sierpinsky(t_screen *s)
{
	s->func = sierpinsky;
	s->maxiter = 5;
	s->minx = 0;
	s->miny = 0;
	s->maxx = 2 * s->image->width;
	s->maxy = 2 * s->image->height;
}

int		init(void *mlx, int type)
{
	static void	(*inits[FRACTALS])(t_screen *) = {init_mandelbrot, init_julia,
		init_burning, init_sierpinsky};
	static char	*names[FRACTALS] = {"Mandelbrot set", "Julia set",
		"Burning Ship", "Sierpinsky carpet"};
	t_screen	*screen;

	if (!(screen = (t_screen*)ft_memalloc(sizeof(t_screen))) ||
	!(screen->win = mlx_new_window(mlx, WIDTH, HEIGHT, names[type])) ||
	!(screen->image = new_image(mlx, WIDTH, HEIGHT)))
		sys_error();
	screen->mlx = mlx;
	screen->maxiter = INIT_ITER;
	inits[type](screen);
	mlx_hook(screen->win, 2, 1L << 0, &key_handle, screen);
	mlx_hook(screen->win, 4, 1L << 2, &mouse_handle, screen);
	mlx_hook(screen->win, 17, 1L << 17, &win_close, screen);
	threads(screen);
	return (1);
}
