/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:57:56 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/16 21:04:24 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	init(void *func(void*), char *name)
{
	t_screen	*screen;

    if (!(screen = (t_screen*)ft_memalloc(sizeof(t_screen))) ||
	!(screen->mlx = mlx_init()) ||
	!(screen->win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, name)) ||
	!(screen->image = new_image(screen->mlx, WIDTH, HEIGHT)))
		sys_error();
	func(screen);
	mlx_hook(screen->win, 2, 1L << 0, &key_handle, screen);
	/*mlx_hook(map->win, 4, 1L << 2, &mouse_handle, map);*/
	mlx_hook(screen->win, 17, 1L << 17, &win_close, screen);
	//matrix_init(map);
	mlx_put_image_to_window(screen->mlx, screen->win, screen->image->img, 0, 0);
	mlx_loop(screen->mlx);
}