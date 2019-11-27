#include <mlx.h>
#include "libft/libft.h"

int main(int ac, char **av)
{
    void *mlx;
    void *win;
    

    if (!(mlx = mlx_init()))
        {
            ft_printf("sdfgds");
            return (0);
        };
    win = mlx_new_window(mlx, 200, 300, "wind");
    mlx_loop(mlx);
    return (0);
}