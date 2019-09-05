/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:24:46 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 21:25:35 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	void	*tmp;

	if (!(tmp = malloc(num)))
		return (NULL);
	ft_memcpy(tmp, src, num);
	ft_memcpy(dst, tmp, num);
	free(tmp);
	return (dst);
}
