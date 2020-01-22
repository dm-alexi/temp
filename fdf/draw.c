/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:44:17 by sscarecr          #+#    #+#             */
/*   Updated: 2020/01/21 21:33:29 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
/*
void	image_clear(t_image *image)
{
	for (int i = 0; i < image->width * image->height * image->bpp / 8; ++i)
		image->s[i] = 0;
}
*/
int red (int color)
{
    return (color >> 16);
}

int green(int color)
{
    return (color >> 8) & 0xFF;
}

int blue(int color)
{
    return (color & 0xFF);
}

int		gradient(t_vertex *a, t_vertex *b, int steps, int i)
{
	int		stepR;
	int		stepG;
	int		stepB;
	int		color;
	double	k;

	k = (double)i / steps;
	stepR = red(a->color) + (red(b->color) - red(a->color))*k + 0.5;
	stepG = green(a->color) + (green(b->color) - green(a->color))*k + 0.5;
	stepB = blue(a->color) + (blue(b->color) - blue(a->color))*k + 0.5;
	color = (stepR << 16) + (stepG << 8) + stepB;
	return (color);
}

void	image_put_pixel(t_image *image, int x, int y, int color)
{
	int		i;

	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ;
	i = x * image->bpp / 8 + y * image->sizeline;
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


//todo: handle a = b!!!
//handle division by zero
void	image_draw_line(t_image *image, t_vertex *a, t_vertex *b)
{
	double	step;
	int		i;

	i = 0;
	if (a->x == b->x && a->y == b->y)
		image_put_pixel(image, a->x, a->y, a->color);
	else if ((a->x >= b->x && a->y >= b->y) || 
	a->x - b->x > ft_abs(b->y - a->y) || a->y - b->y > ft_abs(b->x - a->x))
		image_draw_line(image, b, a);
	else if (b->x - a->x > ft_abs(b->y - a->y))
	{
		step = (double)(a->y - b->y) / (a->x - b->x);
		while (i < b->x - a->x)
		{
			image_put_pixel(image, a->x + i, a->y + i * step, gradient(a, b, b->x - a->x, i));
			//image_put_pixel(image, a->x + i, a->y + i * step, 0xFFFFFF);
			++i;
		}
	}
	else
	{
		if (a->y == b->y)
			error("y");
		step = (double)(a->x - b->x) / (a->y - b->y);
		while (i <= b->y - a->y)
		{
			image_put_pixel(image, a->x + i * step, a->y + i, gradient(a, b, b->y - a->y, i));
			//image_put_pixel(image, a->x + i * step, a->y + i,  0xFFFFFF);
			++i;
		}
	}
}
