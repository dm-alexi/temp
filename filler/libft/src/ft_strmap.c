/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:56:22 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 10:26:46 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*t;
	char	*str;
	size_t	len;

	if (!s || !f || !(len = ft_strlen(s) + 1) ||
	!(str = (char*)malloc(len)))
		return (NULL);
	t = str;
	while (*s)
		*t++ = f(*s++);
	*t = '\0';
	return (str);
}
