/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:54:23 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 10:43:48 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*t;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 + len2 < len1 || !(len1 + len2 + 1) ||
	!(str = (char*)malloc(len1 + len2 + 1)))
		return (NULL);
	t = str;
	while (*s1)
		*t++ = *s1++;
	while ((*t++ = *s2++))
		;
	return (str);
}
