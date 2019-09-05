/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:33:24 by sscarecr          #+#    #+#             */
/*   Updated: 2019/07/17 20:13:22 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_files.h"

#define BUF_SIZE 8092
#define ERR_1 "File name missing.\n"
#define ERR_2 "Too many arguments.\n"

void	putbuf(char *s, int r)
{
	write(1, s, r);
}

int		main(int argc, char **argv)
{
	char	buf[BUF_SIZE + 1];
	int		f;
	int		r;

	if (argc != 2)
	{
		ft_puterr(argc == 1 ? ERR_1 : ERR_2);
		return (1);
	}
	f = open(argv[1], O_RDONLY);
	if (f == -1)
	{
		ft_puterr("open() error.\n");
		return (1);
	}
	while ((r = read(f, buf, BUF_SIZE)))
		putbuf(buf, r);
	close(f);
	return (0);
}
