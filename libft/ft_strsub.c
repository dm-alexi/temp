/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:08:24 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/07 15:25:24 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*t;

	if (!s || !(str = (char*)malloc(len + 1)))
		return (NULL);
	t = str;
	s += start;
	while ((size_t)(t - str) < len)
		*t++ = *s++;
	*t = '\0';
	return (str);
}
