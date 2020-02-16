/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:53:50 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/16 16:37:07 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//todo: update usage when fractal list is finished
static int	usage(void)
{
	ft_printf("usage: fractol type\n\nFractal types:\n" \
	"\tm : Madnelbrot set\n\tj : Julia set\n");
	return (0);
}

int			main(int ac, char **av)
{
	if (ac < 2 || (ft_strcmp(av[1], "m") && ft_strcmp(av[1], "j")))
		return (usage());
	
	return (0);
}