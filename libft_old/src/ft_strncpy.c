/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:00:14 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 00:09:05 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncpy(char *dst, const char *src, size_t num)
{
	char	*s;

	s = dst;
	while (num && *src)
	{
		--num;
		*s++ = *src++;
	}
	while (num--)
		*s++ = '\0';
	return (dst);
}
