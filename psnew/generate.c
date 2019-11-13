/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:44:00 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/13 21:16:19 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "libft/libft.h"

static int		usage(void)
{
	ft_printf("usage: generate <number> [target_file]\n");
	return (0);
}

static void		error(const char *s)
{
	write(2, "Error: ", 7);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(1);
}

static void		shuffle(int *arr, int n)
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

int				main(int ac, char **av)
{
	int		fd;
	int		n;
	int		i;
	int		*arr;

	if (ac < 2 || ac > 3)
		return (usage());
	if ((n = ft_atoi(av[1])) <= 0)
		error("positive number required.");
	if (!(arr = (int*)malloc(sizeof(int) * n)))
		error("memory allocation failed.");
	i = -1;
	while (++i < n)
		arr[i] = i + 1;
	shuffle(arr, n);
	if ((fd = (open((ac == 3 ? av[2] : "arrnum"),
	O_CREAT | O_WRONLY | O_TRUNC, 0666))) < 0)
		error("file open error.");
	i = 0;
	while (i < n)
		ft_dprintf(fd, "%d ", arr[i++]);
	free(arr);
	close(fd);
	return (0);
}
