/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:23:12 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 10:11:12 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const t_byte	*s1;
	const t_byte	*s2;

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
	return (num ? *s1 - *s2 : 0);
}
