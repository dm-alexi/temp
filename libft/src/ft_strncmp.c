/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:59:41 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 10:06:15 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	t_byte	*str1;
	t_byte	*str2;

	if (s1 == s2)
		return (0);
	str1 = (t_byte*)s1;
	str2 = (t_byte*)s2;
	while (num && *str1 && *str1 == *str2)
	{
		--num;
		++str1;
		++str2;
	}
	return (num ? *str1 - *str2 : 0);
}
