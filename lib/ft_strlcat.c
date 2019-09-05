/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:22:50 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 18:54:47 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	size_t	dlen;

	dlen = 0;
	slen = 0;
	i = 0;
	while (dest[dlen])
		++dlen;
	while (src[slen])
		++slen;
	while (dest[i] && i < size - 1)
		++i;
	if (i == size - 1)
		return (size + slen);
	j = 0;
	while (i < size - 1 && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dlen + slen);
}
