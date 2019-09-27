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

// magic const here
static int	count_positions(int type, int sq)
{
	if (type == 15 || type == 4369)
		return (sq * (sq - 3) + 1);
	if (type == 51)
		return ((sq - 1) * (sq - 1) + 1);
	return ((sq - 1) * (sq - 2) + 1);
}

// magic const here
static int	valid(int i, int j, int type, int sq)
{
	if (type == 15)
		return (i <= sq - 4);
	if (type == 4369)
		return (j <= sq - 4);
    if (type == 51)
		return (i <= sq - 2 && j <= sq - 2);
	if (type < 256)
		return (i <= sq - 2 && j <= sq - 3);
	return (i <= sq - 3 && j <= sq - 2);
}

// magic const here
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

int			**clear_rows(int **arr)
{
    int		**tmp;

    tmp = arr;
    while (*tmp)
		free(*tmp++);
	free(arr);
	return (NULL);
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
		if (valid(i / sq, i % sq, type, sq))
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
