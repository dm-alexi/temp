/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:56:22 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 21:56:55 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*t;
	char	*str;

	if (!(str = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	t = str;
	while (*s)
		*t++ = f(*s++);
	*t = '\0';
	return (str);
}
