/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:35:03 by stristim          #+#    #+#             */
/*   Updated: 2020/02/02 11:14:54 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	ft_menu(t_map *map)
{
	static char			*menu[] = {"Zoom:      +/-", "Move:      Arrows",
		"X turn:    2/8", "Y turn:    4/6", "Z turn:    7/9",
		"Reset:     space", "Stretch:   scroll", "Iso:       Q"};
	static char			*str[] = {"| RED    ", "| BLUE   ", "| PINK   ",
		"| CYAN   ", "| GREEN  ", "| VIOLET ", "| YELLOW ", "| ORANGE ",
		"| AVOCADO", "| WHITE  "};
	static const int	colors[] = {RED, BLUE, PINK, CYAN, GREEN, VIOLET,
		YELLOW, ORANGE, AVOCADO, WHITE};
	int					i;

	mlx_string_put(map->mlx, map->win, 30, 20, WHITE, "Keys:");
	i = -1;
	while (++i < 8)
		mlx_string_put(map->mlx, map->win, 15, 45 + i * 15, WHITE, menu[i]);
	mlx_string_put(map->mlx, map->win, 15, 240, WHITE, "| High    | Low");
	i = 0;
	while (i < 10)
	{
		mlx_string_put(map->mlx, map->win, 15, 270 + i * 20, colors[i], str[i]);
		mlx_string_put(map->mlx, map->win, 115, 270 + i * 20, colors[i],
			str[i]);
		++i;
	}
}
