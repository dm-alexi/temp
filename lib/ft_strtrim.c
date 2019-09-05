/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:09:53 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 22:10:40 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*e;

	while (*s == ' ' || *s == '\t' || *s == '\n')
		++s;
	if (*s == '\0')
		return (ft_strdup(s));
	e = (char *)s;
	while (*e)
		++e;
	while (*--e == ' ' || *e == '\t' || *e == '\n')
		;
	if (!(str = (char*)malloc(e - s + 2)))
		return (NULL);
	ft_strncpy(str, s, e - s + 1);
	*(str + (e - s + 1)) = '\0';
	return (str);
}
