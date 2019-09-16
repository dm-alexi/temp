/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:18:19 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/14 23:39:28 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int intlen(int n)
{
    int len;

    len = 0;
    while (n && ++len)
        n /= 10;
    return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		sign;

	if (!n)
		return (ft_strdup("0"));
	len = intlen(n);
	sign = (n < 0);
	if (!(s = (char*)malloc(len + 1 + sign)))
		return (NULL);
	s[len + sign] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		s[len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (n)
	{
		s[--len] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
