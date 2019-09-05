/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:25:33 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 22:26:40 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(void *ptr, int c, size_t num)
{
	unsigned char	*s;
	unsigned char	*e;
	unsigned char	v;

	v = (unsigned char)c;
	s = (unsigned char*)ptr;
	e = s + num;
	while (s != e && *s != v)
		++s;
	return (s == e ? NULL : (void*)s);
}
