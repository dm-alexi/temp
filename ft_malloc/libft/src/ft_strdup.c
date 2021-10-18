/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:50:32 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 00:34:27 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s;
	size_t	len;

	len = ft_strlen(src) + 1;
	if (!len || !(s = (char*)malloc(len)))
		return (NULL);
	return (ft_strcpy(s, src));
}
