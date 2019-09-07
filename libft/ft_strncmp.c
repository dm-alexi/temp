/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:59:41 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/07 19:19:27 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t num)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (s1 == s2)
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (num && *str1 && *str1 == *str2)
	{
		--num;
		++str1;
		++str2;
	}
	if (!num)
		return (0);
	return (*str1 > *str2 ? 1 : -1);
}
