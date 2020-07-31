/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 11:36:52 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 21:18:10 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void	*p;

	if (new_size == size)
		return (ptr);
	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (!(p = malloc(new_size)))
		return (NULL);
	ft_memcpy(p, ptr, size < new_size ? size : new_size);
	free(ptr);
	return (p);
}
