/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:44:17 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/29 20:46:43 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void    image_draw_line(char *image, t_point *a, t_point *b, int color)
{
    int     i;
    int     m;
    

    if (a->y == b->y)
    {
        i = a->x < b->x ? a->x : b->x;
        m = a->x > b->x ? a->x : b->x;
        while (i < m)
           ((char*)image)[i++ * WIDTH + a->y] = color;
    }
}