/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:58:24 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 00:11:54 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *dst, const char *src, size_t num)
{
	char	*s;

	if (num)
	{
		s = dst;
		while (*s)
			++s;
		while (num && *src)
		{
			--num;
			*s++ = *src++;
		}
		*s = '\0';
	}
	return (dst);
}
