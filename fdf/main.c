/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:08 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/16 20:07:33 by sscarecr         ###   ########.fr       */
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

static void		check_file(char *filename)
{
	int		fd;
	
	if ((fd = open(filename, O_WRONLY)) < 0)
	{
		if (errno == EISDIR)
			sys_error();
	}
	else
		close(fd);
}

int				main(int ac, char **av)
{
	int		fd;
	t_map	*map;

    int *h =  malloc(4);
        *h = 5;

    if (ac < 2)
		return (usage());
	check_file(av[ac - 1]);
	if ((fd = open(av[ac - 1], O_RDONLY)) < 0)
		sys_error();
	map = get_map(fd);
	//show_map(map);
    for (int i = 0; i < map->width; ++i)
        for (int j = 0; j < map->length; ++j)
            ft_printf("%d%s", map->grid[i][j], j == map->length - 1 ? "\n" : " ");
    window(av[ac - 1]);
	close(fd);
    return (0);
}
