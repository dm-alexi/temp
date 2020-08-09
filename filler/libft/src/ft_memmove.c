/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:24:46 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/30 23:25:02 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	const t_byte	*s;
	t_byte			*t;

	if (dst != src)
	{
		t = dst;
		s = src;
		if (s > t)
			while (num--)
				*t++ = *s++;
		else
		{
			s += num - 1;
			t += num - 1;
			while (num--)
				*t-- = *s--;
		}
	}
	return (dst);
}
