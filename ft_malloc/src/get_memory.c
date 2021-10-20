/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:15:37 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/19 21:46:14 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/mman.h>
#include "ft_malloc.h"

t_mempage	*getmempage(size_t len)
{
	t_mempage	*page =
		mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);

	if (page == MAP_FAILED)
		return NULL;
	page.next = NULL;
	page.occupied = NULL;
	page.vacant = (t_area *)((t_byte*)&page + sizeof(t_mempage));
	page.vacant.next = NULL;
}