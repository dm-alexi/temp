/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:57:15 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 10:31:26 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	size_t	len;

	if (!s || !f || !(len = ft_strlen(s) + 1) ||
	!(str = (char*)malloc(len)))
		return (NULL);
	i = 0;
	while (*s)
	{
		*(str + i) = f(i, *s++);
		++i;
	}
	*(str + i) = '\0';
	return (str);
}
