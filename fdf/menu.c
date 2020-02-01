/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stristim <stristim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:35:03 by stristim          #+#    #+#             */
/*   Updated: 2020/02/01 20:52:02 by stristim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#define WHITE 0xFFFFFF
# define MIDCOLOR 0xFFFFFF
# define BLUE 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define VIOLET 0xFF00FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define PINK 0xFF0080
# define ORANGE 0xFF8000
# define AVOCADO 0x00FF80

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
    mlx_string_put(map->mlx, map->win, 15, 310, CYAN, "CYAN");
    mlx_string_put(map->mlx, map->win, 15, 330, PINK, "PINK");
    mlx_string_put(map->mlx, map->win, 15, 350, YELLOW, "YELLOW");
    mlx_string_put(map->mlx, map->win, 15, 370, LIGHT_BLUE, "CYAN");
    mlx_string_put(map->mlx, map->win, 15, 390, PINK, "PINK");
    mlx_string_put(map->mlx, map->win, 15, 410, ORANGE, "ORANGE");
    mlx_string_put(map->mlx, map->win, 15, 430, AVOCADO, "AVOCADO");
    mlx_string_put(map->mlx, map->win, 110, 270, BLUE, "BLUE");
    mlx_string_put(map->mlx, map->win, 110, 290, RED, "RED");
    mlx_string_put(map->mlx, map->win, 110, 310, GREEN, "GREEN");
    mlx_string_put(map->mlx, map->win, 110, 330, VIOLET, "VIOLET");
    mlx_string_put(map->mlx, map->win, 110, 350, YELLOW, "YELLOW");
    mlx_string_put(map->mlx, map->win, 110, 370, LIGHT_BLUE, "CYAN");
    mlx_string_put(map->mlx, map->win, 110, 390, PINK, "PINK");
    mlx_string_put(map->mlx, map->win, 110, 410, ORANGE, "ORANGE");
    mlx_string_put(map->mlx, map->win, 110, 430, AVOCADO, "AVOCADO");
    
}