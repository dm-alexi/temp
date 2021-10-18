/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:09:53 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 10:49:32 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*e;

	if (!s)
		return (NULL);
	while (ft_isspace(*s))
		++s;
	if (*s == '\0')
		return (ft_memalloc(1));
	e = (char *)s;
	while (*e)
		++e;
	while (ft_isspace(*--e))
		;
	if (!(str = (char*)malloc(e - s + 2)))
		return (NULL);
	ft_strncpy(str, s, e - s + 1);
	*(str + (e - s + 1)) = '\0';
	return (str);
}
