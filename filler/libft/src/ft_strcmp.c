/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:47:50 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 10:12:03 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	t_byte	*str1;
	t_byte	*str2;

	if (s1 == s2)
		return (0);
	str1 = (t_byte*)s1;
	str2 = (t_byte*)s2;
	while (*str1 && *str1 == *str2)
	{
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}
