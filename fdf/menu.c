/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stristim <stristim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:35:03 by stristim          #+#    #+#             */
/*   Updated: 2020/01/31 21:07:19 by stristim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void ft_menu(t_map *map)
{
    mlx_string_put(map->mlx, map->win, 30, 20, 0xFFFFFF, "Keys:");
	mlx_string_put(map->mlx, map->win, 15, 45, 0xFFFFFF, "Zoom:     +/-");
	mlx_string_put(map->mlx, map->win, 15, 60, 0xFFFFFF, "Move:     Arrows");
    mlx_string_put(map->mlx, map->win, 15, 75, 0xFFFFFF, "X turn:   2/8");
    mlx_string_put(map->mlx, map->win, 15, 90, 0xFFFFFF, "Y turn:   4/6");
    mlx_string_put(map->mlx, map->win, 15, 105, 0xFFFFFF, "Z turn:   7/9");
    mlx_string_put(map->mlx, map->win, 15, 120, 0xFFFFFF, "Reset:    space");
    mlx_string_put(map->mlx, map->win, 15, 135, 0xFFFFFF, "Flatten:  mouse");
}