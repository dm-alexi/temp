/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:01:54 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 10:34:54 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (n && *s1 == *s2)
	{
		if (!*s1)
			return (1);
		--n;
		++s1;
		++s2;
	}
	return (!n);
}
