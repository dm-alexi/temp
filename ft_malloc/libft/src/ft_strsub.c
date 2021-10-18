/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:08:24 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 10:41:12 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*t;

	if (!s || !(len + 1) || !(str = (char*)malloc(len + 1)))
		return (NULL);
	t = str;
	s += start;
	while (len--)
		*t++ = *s++;
	*t = '\0';
	return (str);
}
