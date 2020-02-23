/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:57:56 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/22 16:42:04 by sscarecr         ###   ########.fr       */
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
	screen->maxiter = INIT_ITER;
	screen->func = func;
	screen->zoom = 1.0;
	screen->minx = -2.0;
	screen->miny = -2.0;
	screen->maxx = 2.0;
	screen->maxy = 2.0;
	mlx_hook(screen->win, 2, 1L << 0, &key_handle, screen);
	mlx_hook(screen->win, 4, 1L << 2, &mouse_handle, screen);
	if (func == julia)
	{
		mlx_hook(screen->win, 6, 1L << 6, &mouse_move, screen);
		screen->c.re = JULIA_RE;
		screen->c.im = JULIA_IM;
	}
	mlx_hook(screen->win, 17, 1L << 17, &win_close, screen);
	func(screen);
	mlx_loop(screen->mlx);
}
