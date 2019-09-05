/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:16:14 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 22:27:38 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t num)
{
	char	*s;
	char	*t;

	t = (char*)dst;
	s = (char*)src;
	while (num && (*t++ = *s++) != c)
		--num;
	return (num ? (void*)t : NULL);
}
