/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:24:21 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 00:17:20 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *str, int val)
{
	char	c;
	char	*s;

	c = (char)val;
	s = NULL;
	while (*str)
	{
		if (*str == c)
			s = (char*)str;
		++str;
	}
	return (c == '\0' ? (char*)str : s);
}
