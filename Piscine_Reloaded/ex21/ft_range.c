/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:04:48 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/04 23:05:24 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*p;
	int		*k;
	int		n;

	if (min >= max)
		return (NULL);
	n = max - min;
	p = (int*)malloc(sizeof(int) * n);
	k = p;
	while (min < max)
		*k++ = min++;
	return (p);
}
