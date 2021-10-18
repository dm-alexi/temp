/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.school-21.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:15:37 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/18 20:54:52 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/mman.h>
#include "ft_malloc.h"

t_mempage	*getmempage(size_t len)
{
	t_mempage	*page =
		mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, 0, 0);

	if (page == MAP_FAILED)
		return NULL;
	
}