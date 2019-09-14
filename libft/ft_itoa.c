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

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		k;

	if (!n)
		return (ft_strdup("0"));
	len = 0;
	k = n;
	while (k && ++len)
		k /= 10;
	if (!(s = (char*)malloc(len + 1 + (n < 0))))
		return (NULL);
	s[len + (n < 0)] = '\0';
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
