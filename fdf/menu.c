/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stristim <stristim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:35:03 by stristim          #+#    #+#             */
/*   Updated: 2020/02/01 21:15:41 by stristim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void ft_menu(t_map *map)
{
    mlx_string_put(map->mlx, map->win, 30, 20, WHITE, "Keys:");
    mlx_string_put(map->mlx, map->win, 15, 45, WHITE, "Zoom:     +/-");
    mlx_string_put(map->mlx, map->win, 15, 60, WHITE, "Move:     Arrows");
    mlx_string_put(map->mlx, map->win, 15, 75, WHITE, "X turn:   2/8");
    mlx_string_put(map->mlx, map->win, 15, 90, WHITE, "Y turn:   4/6");
    mlx_string_put(map->mlx, map->win, 15, 105, WHITE, "Z turn:    7/9");
    mlx_string_put(map->mlx, map->win, 15, 120, WHITE, "Reset:     space");
    mlx_string_put(map->mlx, map->win, 15, 135, WHITE, "Stretch:   scroll");
    mlx_string_put(map->mlx, map->win, 15, 150, WHITE, "ISO:       Q");
    mlx_string_put(map->mlx, map->win, 15, 245, WHITE, "High   |  Low");
    mlx_string_put(map->mlx, map->win, 15, 270, RED, "RED");
    mlx_string_put(map->mlx, map->win, 15, 290, BLUE, "BLUE");
    mlx_string_put(map->mlx, map->win, 15, 310, PINK, "PINK");
    mlx_string_put(map->mlx, map->win, 15, 330, CYAN, "CYAN");
    mlx_string_put(map->mlx, map->win, 15, 350, GREEN, "GREEN");
    mlx_string_put(map->mlx, map->win, 15, 370, VIOLET, "VIOLET");
    mlx_string_put(map->mlx, map->win, 15, 390, PINK, "PINK");
    mlx_string_put(map->mlx, map->win, 15, 410, ORANGE, "ORANGE");
    mlx_string_put(map->mlx, map->win, 15, 430, AVOCADO, "AVOCADO");
    mlx_string_put(map->mlx, map->win, 110, 270, RED, "RED");
    mlx_string_put(map->mlx, map->win, 110, 290, BLUE, "BLUE");
    mlx_string_put(map->mlx, map->win, 110, 310, PINK, "PINK");
    mlx_string_put(map->mlx, map->win, 110, 330, CYAN, "CYAN");
    mlx_string_put(map->mlx, map->win, 110, 350, GREEN, "GREEN");
    mlx_string_put(map->mlx, map->win, 110, 370, VIOLET, "VIOLET");
    mlx_string_put(map->mlx, map->win, 110, 390, PINK, "PINK");
    mlx_string_put(map->mlx, map->win, 110, 410, ORANGE, "ORANGE");
    mlx_string_put(map->mlx, map->win, 110, 430, AVOCADO, "AVOCADO");
    
}