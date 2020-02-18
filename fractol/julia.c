/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:27:55 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/18 20:14:35 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	map_coord(t_complex *z, t_screen *s, int x, int y)
{
	z->re = 2 * ((2 * (double)x - s->image->width) / s->image->width);
	z->im = 2 * ((2 * (double)y - s->image->height) / s->image->height);
}

void	*julia(void *param)
{
	t_screen	*s;
	t_complex	z;
	int			x;
	int			y;
	int			i;

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
