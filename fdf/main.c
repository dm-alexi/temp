/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:08 by sscarecr          #+#    #+#             */
/*   Updated: 2020/01/22 21:31:10 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "fdf.h"

static int		usage(void)
{
	ft_printf("usage: fdf filename\n");
	return (0);
}

int				main(int ac, char **av)
{
	int		fd;
	t_map	*map;

	if (ac < 2)
		return (usage());
	if ((fd = open(av[ac - 1], O_RDONLY)) < 0)
		sys_error();
	map = get_map(fd);
	close(fd);
	//ft_printf("%d %d", map->z_min, map->z_max);
	//show_map(map);
/*
    for (int i = 0; i < map->rows; ++i)
        for (int j = 0; j < map->columns; ++j)
            ft_printf("%2d%s", map->grid[i * map->columns + j].z, j == map->columns - 1 ? "\n" : " ");
*/
	fdf_init(av[ac - 1], map);

	return (0);
}
