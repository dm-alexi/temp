/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stristim <stristim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:42:34 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/05 18:40:01 by stristim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"

static int		moveupleft(int n)
{
	static const int	legal[19] = {15, 23, 39, 51, 54, 71, 99, 113, 114, 116,
	275, 305, 306, 547, 561, 562, 785, 802, 4369};
	int					i;

	if (!n)
		return (-1);
	while (!(n & 15))
		n >>= 4;
	while (!(n & 4369))
		n >>= 1;
	i = 0;
	while (i < 19)
		if (n == legal[i++])
			return (n);
	return (-1);
}

static int		get_figure(int fd)
{
	char	s[20];
	int		r;
	int		i;
	int		res;

	if ((r = read(fd, s, 20)) < 20)
		return (r ? -1 : 0);
	res = 0;
	i = 0;
	while (i < r)
	{
		if (i % 5 == 4)
		{
			if (s[i] != '\n')
				return (-1);
		}
		else if (s[i] == '#')
			res = res | (1 << (i - i / 5));
		else if (s[i] != '.')
			return (-1);
		++i;
	}
	return (moveupleft(res));
}

int				*get_figures(char *s, int *n)
{
	int		fd;
	int		k;
	int		*res;
	int		lines;
	char	c;

	if ((fd = open(s, 0)) < 0)
		return (NULL);
	if (!(res = (int*)malloc(sizeof(int) * 26)))
		exit(1);
	*n = 0;
	lines = 0;
	while ((k = get_figure(fd)) > 0 && *n < 27)
	{
		res[(*n)++] = k;
		if (!((k = read(fd, &c, 1)) == 1 && c == '\n'))
			break ;
		++lines;
	}
	if (k || !*n || *n > 26 || lines == *n)
	{
		free(res);
		res = NULL;
	}
	return (res);
}
