/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:25:33 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/30 23:56:46 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int val, size_t num)
{
	const t_byte	*s;
	t_byte			c;

	c = (t_byte)val;
	s = ptr;
	while (num && *s != c)
	{
		--num;
		++s;
	}
	return (num ? (void*)s : NULL);
}
