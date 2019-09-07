/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:01:54 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 22:15:16 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	while (n && *s1 && *s1 == *s2)
	{
		--n;
		++s1;
		++s2;
	}
	return (!n);
}