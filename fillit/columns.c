/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:22:06 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/30 23:07:03 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_col	*make_columns(int n, int sq)
{
	t_col	*arr;
	int		i;

	if (!(arr = (t_col*)ft_memalloc(sizeof(t_col) * (sq * sq + n + 1))))
		return (NULL);
	i = 0;
	while (++i <= n)
	{
		arr[i].head.u = &(arr[i].head);
		arr[i].head.d = &(arr[i].head);
		arr[i].prev = arr + i - 1;
		arr[i - 1].next = arr + i;
	}
	arr[--i].next = arr;
	arr[0].prev = arr + i;
	while (++i <= n + sq * sq)
	{
		arr[i].head.u = &(arr[i].head);
		arr[i].head.d = &(arr[i].head);
		arr[i].prev = arr + i;
		arr[i].next = arr + i;
		arr[i].order = i - n - 1;
	}
	return (arr);
}

void			del_columns(t_col *arr, int n)
{
	int		i;
	t_node	*t;

	i = 0;
	while (++i <= n)
	{
		while (arr[i].head.d != &(arr[i].head))
		{
			t = arr[i].head.d;
			arr[i].head.d = t->d;
			free(t);
		}
	}
	free(arr);
}

t_col			*make_matrix(int *figures, int n, int sq)
{
	int		i;
	t_col	*arr;

	arr = make_columns(n, sq);
	i = 0;
	while (i < n)
	{
		add_row(arr, get_rows(i + 1, n, figures[i], sq));
		++i;
	}
	return (arr);
}
