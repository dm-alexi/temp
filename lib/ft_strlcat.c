/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:22:50 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 18:24:04 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	slen;
	unsigned int	dlen;

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
