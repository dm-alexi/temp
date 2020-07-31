/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:32:57 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 21:20:12 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function swaps two regions of memory.
** Undefined behavior in case of overlapping.
*/

void	ft_memswap(void *a, void *b, size_t size)
{
	t_byte	*s;
	t_byte	*t;
	size_t	i;

	if (size && a != b)
	{
		s = a;
		t = b;
		i = 0;
		while (i < size)
		{
			*(s + i) ^= *(t + i);
			*(t + i) ^= *(s + i);
			*(s + i) ^= *(t + i);
			++i;
		}
	}
}
