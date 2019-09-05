/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:01:00 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/04 23:02:05 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (*str++)
		++n;
	return (n);
}

char	*ft_strdup(char *src)
{
	int		n;
	char	*s;
	char	*t;

	n = ft_strlen(src);
	s = (char*)malloc(n + 1);
	t = s;
	while ((*t++ = *src++))
		;
	return (s);
}
