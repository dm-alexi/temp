/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:33:55 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 21:50:39 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Insertion sort, stable
*/

void	ft_isort(void *base, size_t num, size_t size,
	int (*compar)(const void*, const void*))
{
	t_byte	*b;
	t_byte	*s;
	t_byte	*t;

	if (!base || num < 2 || !size || !compar)
		return ;
	b = (t_byte*)base;
	s = b;
	while ((s - b) / size < num)
	{
		t = s;
		while (t > b && compar(t - size, t) > 0)
		{
			ft_memswap(t, t - size, size);
			t -= size;
		}
		s += size;
	}
}
