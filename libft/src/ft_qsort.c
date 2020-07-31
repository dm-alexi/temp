/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:51:36 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 21:40:29 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_byte	*partition(void *low, void *high, size_t size,
	int (*compar)(const void*, const void*))
{
	t_byte	*l;
	t_byte	*r;
	t_byte	*p;

	p = (t_byte*)low;
	r = (t_byte*)high;
	l = p + size;
	ft_memswap(p, p + (r - p) / size / 2 * size, size);
	while (1)
	{
		while (l < r && compar(l, p) < 0)
			l += size;
		while (compar(r, p) > 0)
			r -= size;
		if (l >= r)
		{
			ft_memswap(p, r, size);
			return (r);
		}
		ft_memswap(l, r, size);
		l += size;
		r -= size;
	}
}

void			ft_qsort(void *base, size_t num, size_t size,
	int (*compar)(const void*, const void*))
{
	t_byte	*l;
	t_byte	*r;
	t_byte	*p;

	if (!base || num < 2 || !size || !compar)
		return ;
	if (num < 10)
	{
		ft_isort(base, num, size, compar);
		return ;
	}
	l = (t_byte*)base;
	r = l + size * (num - 1);
	p = partition(base, r, size, compar);
	ft_qsort(base, (p - l) / size, size, compar);
	ft_qsort(p + size, (r - p) / size, size, compar);
}
