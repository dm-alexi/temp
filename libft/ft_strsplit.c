/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:10:41 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/07 15:29:50 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	n;

	if (!s)
		return (0);
	n = 0;
	while (*s && *s != c)
		++s;
	while (*s)
	{
		while (*s == c)
			++s;
		++n;
		while (*s && *s != c)
			++s;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	const char	*t;
	char		**arr;
	size_t		n;
	size_t		i;

	n = word_count(s, c);
	if (!s || !(arr = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	i = 0;
	while (*s && *s == c)
		++s;
	t = s;
	while (i < n)
	{
		while (*t && *t != c)
			++t;
		arr[i] = (char*)malloc(t - s + 1);
		ft_strncpy(arr[i], s, t - s);
		arr[i++][t - s] = '\0';
		while (*t == c)
			++t;
		s = t;
	}
	arr[i] = NULL;
	return (arr);
}
