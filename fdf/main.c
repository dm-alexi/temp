/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:08 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/28 23:40:21 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

int		usage(void)
{
	ft_printf("usage: fdf filename\n");
	return (0);
}

int		main(int ac, char **av)
{
    /*void *mlx;
    void *win;

    if (av[ac])
        ft_printf("@");
    if (!(mlx = mlx_init()))
        {
            ft_printf("sdfgds");
            return (0);
        };
    win = mlx_new_window(mlx, 200, 300, "wind");
    for (int i = 0; i < 100; ++i)
        mlx_pixel_put(mlx, win, i, 100, 250);
    mlx_loop(mlx);*/
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
	close(fd);
    /*int *h =  malloc(4);
    *h = 5;*/
    return (0);
}
