/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:53:50 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/23 14:37:57 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//todo: update usage when fractal list is finished

static int	usage(void)
{
	ft_printf("usage: [j | m | ]fractol type\n\nFractal types:\n" \
	"\tm : Madnelbrot set\n\tj : Julia set\n");
	return (0);
}

int			main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ft_strequ(av[1], "m"))
			init(mandelbrot, "Mandelbrot set");
		else if (ft_strequ(av[1], "j"))
			init(julia, "Julia set");
	}
	else
		return (usage());
	return (0);
}
