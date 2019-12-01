/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:08 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/01 16:29:23 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

static int	usage(void)
{
	ft_printf("usage: fdf filename\n");
	return (0);
}

int			main(int ac, char **av)
{
	int		fd;
	t_map	*map;

    int *h =  malloc(4);
        *h = 5;

    if (ac < 2)
		return (usage());
    if ((fd = open(av[ac - 1], O_RDONLY)) < 0)
		sys_error();
	map = get_map(fd);
	//show_map(map);
    for (int i = 0; i < map->width; ++i)
    {
        for (int j = 0; j < map->length; ++j)
            ft_printf("%d ", map->grid[i][j]);
            ft_printf("\n");
    }
    window(av[ac - 1]);
	close(fd);
    return (0);
}
