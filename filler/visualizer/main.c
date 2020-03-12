/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:24:35 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/12 21:35:32 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef _WIN32
# include <stdio.h>
#else
# include <unistd.h>
#endif
#include <fcntl.h>
#include "visual.h"

static int  usage(void)
{
    ft_printf("usage: visual [filename]\n");
	return (0);
}

int main(int ac, char **av)
{
    int     fd;
    t_game  game;

    if (ac > 2)
        return(usage());
    fd = (ac == 2 ? open(av[ac - 1], O_RDONLY) : STDIN_FILENO);
    if (fd < 0)
		sys_error();
	input(fd, &game);
	close(fd);
	//fdf_init(av[ac - 1], map);
    //delete(&game);
    return (0);
}
