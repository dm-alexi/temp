/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:22:06 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/25 19:22:08 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

col				*make_columns(int n, int sq)
{
	col		*arr;
	int		i;

	if (!(arr = (col*)ft_memalloc(sizeof(col) * (sq * sq + n + 1))))
		return (NULL);
	i = 0;
	while (++i <= n)
	{
		arr[i].order = i - 1;
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
		arr[i].order = i - 1;
	}
	return (arr);
}
