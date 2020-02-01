/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:35:03 by stristim          #+#    #+#             */
/*   Updated: 2020/02/01 19:09:11 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#define WHITE 0xFFFFFF

void ft_menu(t_map *map)
{
    mlx_string_put(map->mlx, map->win, 30, 20, WHITE, "Keys:");
    mlx_string_put(map->mlx, map->win, 15, 45, WHITE, "Zoom:     +/-");
    mlx_string_put(map->mlx, map->win, 15, 60, WHITE, "Move:     Arrows");
    mlx_string_put(map->mlx, map->win, 15, 75, WHITE, "X turn:   2/8");
    mlx_string_put(map->mlx, map->win, 15, 90, WHITE, "Y turn:   4/6");
    mlx_string_put(map->mlx, map->win, 15, 105, WHITE, "Z turn:   7/9");
    mlx_string_put(map->mlx, map->win, 15, 120, WHITE, "Reset:    space");
    mlx_string_put(map->mlx, map->win, 15, 135, WHITE, "Flatten:  mouse");
}