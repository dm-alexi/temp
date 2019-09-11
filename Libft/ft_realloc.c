/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 11:36:52 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/11 22:03:37 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void	*p;

	if (new_size == size)
		return (ptr);
	if (!(p = malloc(new_size)))
		return (NULL);
	ft_memcpy(p, ptr, size < new_size ? size : new_size);
	free(ptr);
	return (p);
}
