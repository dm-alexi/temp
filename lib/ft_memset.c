/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:25:56 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 21:27:13 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	unsigned char	c;
	unsigned char	*s;

	c = (unsigned char)ch;
	s = (unsigned char*)buf;
	while (count--)
		*s++ = c;
	return (buf);
}
