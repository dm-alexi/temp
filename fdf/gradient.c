/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stristim <stristim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:42:42 by stristim          #+#    #+#             */
/*   Updated: 2020/01/23 21:49:26 by stristim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int gradient(int start, int finish, double k)
{
    // I = start + (end - start) * K
    // K = i / line
    int stepR;
    int stepG;
    int stepB;
    int color;

    stepR = red(start) + (red(finish) - red(start))*k + 0.5;
    stepG = green(start) + (green(finish) - green(start))*k  + 0.5;
    stepB = blue(start) + (blue(finish) - blue(start))*k + 0.5;
    color = (stepR << 16) | (stepG << 8) | stepB;
    return (color);
}

int gradient_check(t_vertex *a, t_vertex *b, int steps, int i)
{
    int length;
    double k;
    double l;
    int color;

    k = (double)i/steps;
    length = ft_abs(a->z) + ft_abs(b->z);
    if ((a->z > 0 && b->z > 0) || (a->z < 0 && b->z < 0))
        color = gradient(a->color, b->color, k);
    else if (a->z < 0)
    {
        l = (double)(length - b->z) / length;
        if (k < l)
            color = gradient(a->color, MIDCOLOR, k);
        else
            color = gradient(MIDCOLOR, b->color, k);
    }
    else
    {
        l = (double)(length - a->z) / length;
        if(k > l)
            color = gradient(a->color, MIDCOLOR, k);
        else
            color = gradient(MIDCOLOR, b->color, k);
    }
    return (color);
}
