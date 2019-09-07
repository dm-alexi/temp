/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:03:02 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/07 17:52:33 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*s;

	if (!(str = (char*)malloc(++size)))
		return (NULL);
	s = str;
	while (size--)
		*s++ = '\0';
	return (str);
}
