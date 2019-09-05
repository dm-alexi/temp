/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:09:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 19:29:33 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char    *ft_strstr(const char *s1, const char *s2)
{
	size_t	n1;
	size_t	n2;
	char	*s;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	if (n2 > n1)
		return (NULL);
	s = (char*)s1;
	while ((size_t)(s - s1) <= n1 - n2)
	{
		if (*s == *s2 && !ft_strncmp(s, s2, n2))
			return (s);
		++s;
	}
    return (NULL);
}
