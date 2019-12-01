/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:44:17 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/01 17:23:19 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	image_put_pixel(t_image *image, int x, int y, int color)
{
	int		i;
	
	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ;
	i = x * image->bpp / 8 + y * image->width;
	if (image->endian)
	{
		if (image->bpp > 24)
			image->s[i++] = 0;
		image->s[i++] = color >> 16;
		image->s[i++] = color >> 8;
		image->s[i] = color;
	}
	else
	{
		image->s[i++] = color;
		image->s[i++] = color >> 8;
		image->s[i++] = color >> 16;
		if (image->bpp > 24)
			image->s[i] = 0;
	}
}

void    image_draw_line(t_image *image, t_dot *a, t_dot *b)
{
    double	step;
	int		m;
	double	n;

	if (a->x > b->x)
		ft_memswap(a, b, sizeof(t_dot));
	//a-> == b->y | a->x == b->x
	if (b->x - a->x > ft_abs(b->y - a->y))
	{
		step = (double)(a->y - b->y) / (a->x - b->x);
		m = a->x;
		n = a->y;
		while (m <= b->x)
		{
			image_put_pixel(image, m++, (int)n, 0xffffffff);
			n += step;
		}
	}
	else
	{
		if (a->y > b->y)
			ft_memswap(a, b, sizeof(t_dot));
		step = (double)(a->x - b->x) / (a->y - b->y);
		m = a->y;
		n = a->x;
		while (m <= b->y)
		{
			image_put_pixel(image, (int)n, m++, 0xffffffff);
			n += step;
		}
	}
}