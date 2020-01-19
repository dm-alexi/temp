/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stristim <stristim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:56:39 by stristim          #+#    #+#             */
/*   Updated: 2020/01/19 19:41:50 by stristim         ###   ########.fr       */
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

int gradient(t_dot *a, t_dot *b, int steps, int i)
{
    int stepR;
    int stepG;
    int stepB;
    int color;
    double k;

    k = (double)i / steps;
    stepR = red(a->color) + (red(b->color) - red(a->color))*k;
    stepG = green(a->color) + (green(b->color) - green(a->color))*k;
    stepB = blue(a->color) + (blue(b->color) - red(a->color))*k;
    color = (stepR << 16) + (stepG << 8) + stepB;
    return (color);
}
