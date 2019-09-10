/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:23:12 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/10 20:21:43 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char		*s1;
	const unsigned char		*s2;

	if (ptr1 == ptr2)
		return (0);
	s1 = ptr1;
	s2 = ptr2;
	while (num && *s1 == *s2)
	{
		--num;
		++s1;
		++s2;
	}
	if (!num)
		return (0);
	return ((int)*s1 - (int)*s2);
}
