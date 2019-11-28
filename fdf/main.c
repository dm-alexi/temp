//#include <mlx.h>
#include <fcntl.h>
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

    if (!(mlx = mlx_init()))
        {
            ft_printf("sdfgds");
            return (0);
        };
    win = mlx_new_window(mlx, 200, 300, "wind");
    mlx_loop(mlx);*/
	int		fd;
	t_map	*map;

    if (ac < 2)
		return (usage());
    if ((fd = open(av[ac - 1], O_RDONLY) < 0))
		error();
	map = get_map(fd);
	//show_map(map);
	close(fd);
    return (0);
}
