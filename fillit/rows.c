/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:21:38 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/25 19:21:40 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	count_positions(int type, int sq)
{
	if (type == 15 || type == 4369)
		return (sq * (sq - 3) + 1);
	if (type == 51)
		return ((sq - 1) * (sq - 1) + 1);
	return ((sq - 1) * (sq - 2) + 1);
}

static int	valid(int i, int type, int sq)
{
	if (type == 15)
		return (i % sq <= sq - 4);
	if (type == 4369)
		return (i / sq <= sq - 4);
    if (type == 51)
		return (i / sq <= sq - 2 && i % sq <= sq - 2);
	if (type < 256)
		return (i / sq <= sq - 2 && i % sq <= sq - 3);
	return (i / sq <= sq - 3 && i % sq <= sq - 2);
}

static int	*arr_fill(int n, int num, int type, int sq)
{
	int		*res;
	int		i;
	int		j;
	int		degree;

	if (!(res = (int*)malloc(sizeof(int) * 5)))
		return (NULL);
	i = 1;
	j = 1;
	degree = 0;
	while (degree < 13)
	{
		if (type & j)
            res[i++] = n + degree % 4 + sq * (degree / 4) + num + 1;
		++degree;
		j <<= 1;
	}
	return (res);
}

int			**get_rows(int ord, int num, int type, int sq)
{
	int		n;
	int		i;
	int		k;
	int		**arr;

	n = count_positions(type, sq);
    if (!(arr = (int**)malloc(sizeof(int*) * n)))
		exit(1);
	k = 0;
	i = 0;
	while (i < sq * sq)
	{
		if (valid(i, type, sq))
		{
			if (!(arr[k] = arr_fill(i, num, type, sq)))
				exit(1);
			arr[k++][0] = ord;
		}
		++i;
	}
	arr[k] = NULL;
	return (arr);
}
