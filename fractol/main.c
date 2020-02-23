/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:53:50 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/23 18:35:10 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

//todo: update usage when fractal list is finished

static int	usage(void)
{
	ft_printf("usage: fractol [m | j | b]\n\nFractal types:\n" \
	"\tm : Madnelbrot set\n\tj : Julia set\n\tb : Burning Ship\n");
	return (0);
}

static int	get_fractal(void *mlx, char *arg)
{
	static const char	*types[FRACTALS] = {"m", "j", "b"};
	int					i;

	i = 0;
	while (i < FRACTALS)
	{
		if (ft_strequ(arg, types[i]))
			return (init(mlx, i));
		++i;
	}
	return (0);
}

int			counter(int x)
{
	static int	count = 0;

	count += x;
	return (count);
}

int			main(int ac, char **av)
{
	void	*mlx;
	int		i;
	int		count;

	count = 0;
	if (ac > 1)
	{
		if (!(mlx = mlx_init()))
			sys_error();
		i = 0;
		while (++i < ac)
			if (get_fractal(mlx, av[i]))
				++count;
			else
				ft_printf("Illegal option: %s\n", av[i]);
	}
	if (!counter(count))
		return (usage());
	mlx_loop(mlx);
	return (0);
}
