/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:25:56 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/30 14:46:55 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t num)
{
	t_byte	c;
	t_byte	*s;

	c = (t_byte)val;
	s = ptr;
	while (num--)
		*s++ = c;
	return (ptr);
}
