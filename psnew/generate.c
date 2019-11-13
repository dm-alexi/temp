#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "libft/libft.h"

int		usage(void)
{
	ft_printf("Usage: generate <number> [-filename]\n");
	return (0);
}

void	shuffle(int *arr, int n)
{
	int		i;
	int		r;
	int		tmp;

	srand(time(NULL));
	i = n - 1;
	while (i > 0)
	{
		r = rand() % (i + 1);
		tmp = arr[i];
		arr[i] = arr[r];
		arr[r] = tmp;
		--i;
	}
}

int		main(int ac, char **av)
{
    int		fd;
    int		n;
    int		i;
    int		*arr;

    if (ac < 2 || ac > 4)
		return (usage());
	if ((n = ft_atoi(av[1])) <= 0 || !(arr = (int*)malloc(sizeof(int * n))))
		error();
	i = -1;
	while (++i < n)
		arr[i] = i + 1;
	shuffle(arr, n);
	if ((fd = (open(ac == 3 ? av[2] : "arrnum", O_WRONLY | O_CREAT))) < 0)
		error();
	i = 0;
	while (i < n)
		ft_dprintf(fd, "%d ", arr[i++]);
	close(fd);
    return 0;
}
