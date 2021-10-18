/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:16:14 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/30 14:55:00 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int val, size_t num)
{
	const t_byte	*s;
	t_byte			*t;
	t_byte			c;

	t = dst;
	s = src;
	c = (t_byte)val;
	while (num && (*t++ = *s++) != c)
		--num;
	return (num ? (void*)t : NULL);
}
