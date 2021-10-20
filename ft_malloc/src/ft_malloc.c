/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:52:33 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/20 23:36:03 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/mman.h>
#include "ft_malloc.h"

g_mutex = PTHREAD_MUTEX_INITIALIZER;
g_pages = (t_pages){NULL, NULL, NULL};

t_area	*alloc_area_on_new_page(t_page *first, int page_size, int size);
{
	t_area	*area;
	t_page	*page;
	
	page = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (page == MAP_FAILED)
		return NULL;
	if (first)
		first->prev = page;
	page->prev = NULL;
	page->next = first;
	*first = page;
	area = (t_area*)((byte*)page + sizeof(t_page));
	if (size > page_size - sizeof(t_page) - 2 * sizeof(t_area) - MINSIZE)
		*area = (t_area){.prev = NULL, .next = NULL, .status = OCCUPIED
			.size = size - sizeof(t_page) - sizeof(t_area)};
	else
	{
		*area = (t_area){.prev = NULL, .size = size, .status = OCCUPIED,
			.next = area->next = (t_area*)((byte*)area + sizeof(t_area) + size)};
		*(area->next) = (t_area){.prev = area, .next = NULL, .status = VACANT,
				.size = page_size - size - sizeof(t_page) - 2 * sizeof(t_area)};
	}
	return area;
}

void	*alloc_area(t_page *first, int page_size, int size)
{
	t_page	*page;
	t_area	*min_area = NULL;

	if (size <= page_size - sizeof(t_page) - sizeof(t_area))
		for (page = first; page; page = page->next)
		{
			t_area	*area = (t_area*)((byte*)page + sizeof(t_page));
			for (; area && !(area->size == size && area->status == VACANT); area = area->next)
				if (area->status == VACANT && area->size > size && (!min_area || min_area->size > area->size))
					min_area = area;
			if (area && (area->status = OCCUPIED))
				return (void*)((byte*)area + sizeof(t_area));
		}
	if (!min_area)
		min_area = alloc_area_on_new_page(first, page_size, size);
	if (min_area)
		return (void*)((byte*)min_area + sizeof(t_area));
	return NULL;
}

void	*alloc_big(size_t size)
{
	t_big	*ptr; 
	
	ptr = mmap(NULL, size + sizeof(t_big), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (ptr == MAP_FAILED)
		return NULL;
	if (g_pages.big)
		g_pages.big->prev = ptr;
	ptr->prev = NULL;
	ptr->next = g_pages.big;
	ptr->size = size;
	g_pages.big = ptr;
	return (void*)((byte*)ptr + sizeof(t_big));
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	if (!size)
		return NULL;
	size = roundup(size);
	pthread_mutex_lock(&g_mutex);
	if (size + sizeof(t_area) <= TINYSIZE - sizeof(t_page))
		ptr = alloc_area(&g_pages.tiny, TINYSIZE, size);
	else if (size + sizeof(t_area) <= SMALLSIZE - sizeof(t_page))
		ptr = alloc_area(&g_pages.small, SMALLSIZE, size);
	else ptr = alloc_big(size);
	pthread_mutex_lock(&g_mutex);
	return ptr;
}
