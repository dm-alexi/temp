/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:57:56 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/24 17:46:01 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	init_julia(t_screen *s)
{
	s->func = julia;
	s->maxiter = INIT_ITER;
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
	s->maxiter = INIT_ITER;
	s->minx = -2.0;
	s->miny = -2.0;
	s->maxx = 2.0;
	s->maxy = 2.0;
}

void	init_multibrot(t_screen *s)
{
	s->func = multibrot;
	s->maxiter = INIT_ITER;
	s->minx = -2.0;
	s->miny = -2.0;
	s->maxx = 2.0;
	s->maxy = 2.0;
	s->degree = 3;
}

void	init_burning(t_screen *s)
{
	s->func = burning;
	s->maxiter = INIT_ITER;
	s->minx = -2.0;
	s->miny = -2.0;
	s->maxx = 2.0;
	s->maxy = 2.0;
}

void	init_sierpinsky(t_screen *s)
{
	s->func = sierpinsky;
	s->maxiter = 16;
	s->minx = 0;
	s->miny = 0;
	s->maxx = s->image->width;
	s->maxy = s->image->height;
}
