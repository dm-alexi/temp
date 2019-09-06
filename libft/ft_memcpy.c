/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:20:31 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 21:22:51 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	const unsigned char	*s;
	unsigned char	*t;

	if (dst == src)
        return (dst);
	t = dst;
	s = src;
	while (num--)
		*t++ = *s++;
	return (dst);
}
