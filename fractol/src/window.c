/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:32:30 by sscarecr          #+#    #+#             */
/*   Updated: 2020/10/26 15:10:09 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "mlx_events.h"
#include "fractol.h"

static int	win_close(void *param)
{
	t_screen	*s;

	s = param;
	mlx_destroy_window(s->mlx, s->win);
	mlx_destroy_image(s->mlx, s->image->img);
	free(s->image);
	free(s);
	if (!counter(-1))
		exit(EXIT_SUCCESS);
	return (0);
}

int			init(void *mlx, int type)
{
	static void	(*inits[FRACTALS])(t_screen *) = {init_mandelbrot, init_julia,
		init_burning, init_multibrot, init_sierpinsky};
	static char	*names[FRACTALS] = {"Mandelbrot set", "Julia set",
		"Burning Ship", "Multibrot set", "Sierpinsky carpet"};
	t_screen	*screen;

	if (!(screen = (t_screen*)ft_memalloc(sizeof(t_screen))) ||
	!(screen->win = mlx_new_window(mlx, WIDTH, HEIGHT, names[type])) ||
	!(screen->image = new_image(mlx, WIDTH, HEIGHT)))
		sys_error();
	screen->mlx = mlx;
	inits[type](screen);
	mlx_hook(screen->win, KEY_PRESS, KEY_PRESS_MASK, &key_handle, screen);
	mlx_hook(screen->win, BUTTON_PRESS, BUTTON_PRESS_MASK, &mouse_handle, screen);
	mlx_hook(screen->win, 17, 1L << 17, &win_close, screen);
	threads(screen);
	return (1);
}

void		reset(t_screen *s)
{
	static void	*(*funcs[FRACTALS])(void *) = {mandelbrot, julia, burning,
		multibrot, sierpinsky};
	static void	(*inits[FRACTALS])(t_screen *) = {init_mandelbrot, init_julia,
		init_burning, init_multibrot, init_sierpinsky};
	int			i;

	i = -1;
	while (++i < FRACTALS)
		if (s->func == funcs[i])
		{
			inits[i](s);
			return ;
		}
}
