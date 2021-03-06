/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:48:23 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/07 11:41:24 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char	*s;

	if (dst == src)
		return (dst);
	s = dst;
	while ((*s++ = *src++))
		;
	return (dst);
}
