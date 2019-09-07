/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:25:33 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/07 11:37:22 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *ptr, int val, size_t num)
{
	const unsigned char		*s;
	unsigned char			c;

	c = (unsigned char)val;
	s = ptr;
	while (num && *s != c)
	{
		--num;
		++s;
	}
	return (num ? NULL : (void*)s);
}