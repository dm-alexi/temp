/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:20:31 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/30 14:52:15 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	const t_byte	*s;
	t_byte			*t;

	if (dst != src)
	{
		t = dst;
		s = src;
		while (num--)
			*t++ = *s++;
	}
	return (dst);
}
