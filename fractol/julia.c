/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:27:55 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/16 22:12:50 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void map_coord(t_complex *z, t_image *image, int x, int y)
{
	z->re = (double)(y - image->height / 2) / image->height;
	z->im = (double)(x - image->width / 2) / image->width;
}

void	*julia(void *param)
{
	t_screen	*s;
	int			x;
	int			y;
	t_complex	c;
	t_complex	z;

	c.re = -0.7;
	c.im = 0.27015;
	s = param;
	y = -1;
	while (++y < s->image->height)
	{
		x = -1;
		while (++x < s->image->width)
		{
			map_coord(&z, s->image, x, y);
		}
	}
    
	return (NULL);
}
