/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:19:58 by sscarecr          #+#    #+#             */
/*   Updated: 2020/01/24 20:41:54 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	fdf_init(char *file, t_map *map)
{
	if (!(map->mlx = mlx_init()) ||
		!(map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, file)) ||
		!(map->image = new_image(map->mlx, WIDTH, HEIGHT)))
		sys_error();
	//mlx_key_hook(map->win, &key_handle, map);
	mlx_hook(map->win, 2, 1L<<1, &key_handle, map);
	mlx_hook(map->win, 17, 1L << 17, &win_close, map);
	matrix_init(map);
	matrix_result(map);
	ft_menu(map);
	mlx_loop(map->mlx);
}
