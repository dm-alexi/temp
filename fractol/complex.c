/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:55:37 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/23 18:30:04 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

void	map_coord(t_complex *z, t_screen *s, int x, int y)
{
	z->re = (s->maxx - s->minx) * x / s->image->width + s->minx;
	z->im = (s->maxy - s->miny) * y / s->image->height + s->miny;
}

/*
** square_dist returns square distance, avoiding sqrt() call here
*/

double	square_dist(t_complex *z, t_complex c)
{
	double	t;

	t = z->re * z->re - z->im * z->im + c.re;
	z->im = 2 * z->re * z->im + c.im;
	z->re = t;
	return (z->re * z->re + z->im * z->im);
}

double	square_dist_abs(t_complex *z, t_complex c)
{
	double	t;

	t = fabs(z->re * z->re - z->im * z->im + c.re);
	z->im = fabs(2 * z->re * z->im + c.im);
	z->re = t;
	return (z->re * z->re + z->im * z->im);
}
