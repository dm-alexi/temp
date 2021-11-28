/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:08:35 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/24 18:14:13 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/mman.h>
#include "ft_malloc.h"

void	*realloc_big(void *ptr, size_t size, t_big *big)
{
	void	*p;
	
	if (size + sizeof(t_area) <= SMALLSIZE - sizeof(t_page))
	{
		if ((p = (size + sizeof(t_area) <= TINYSIZE - sizeof(t_page)) ?
			alloc_area(&g_pages.tiny, TINYSIZE, size) : alloc_area(&g_pages.small, SMALLSIZE, size)))
			ft_memcpy(p, ptr, size);
	}
	else if (size <= t_big->size)
		return ptr;
	else if (p = alloc_big(size))
		ft_memcpy(p, ptr, big->size);
	if (p)
		free_big(big);
	return p;
}

void	*realloc_small(void *ptr, int size, t_area *area, t_page *page)
{
	void	*p;
	int		diff = size - area->size;
	int		tmp;
	
	if (diff > 0 && (!area->next || area->next->status == OCCUPIED || area->next->size + sizeof(t_area) < diff))
	{
		if (p = (size + sizeof(t_area) > SMALLSIZE - sizeof(t_page)) ?
			alloc_big(size) : alloc_area(&g_pages.small, SMALLSIZE, size))
		{
			ft_memcpy(p, ptr, area->size);
			free_area(g_pages.small, page, SMALLSIZE, area);
		}
		return p;
	}
	else if (diff > 0 && area->next->size - diff < MINSIZE)
	{
		area->size += sizeof(t_area) + area->next->size;
		area->next = area->next->next;
	}
	else if (diff > 0)
	{
		area->size = size;
		ft_memcpy((byte*)(area->next) + diff, area->next, sizeof(t_area));
		area->next = (t_area*)((byte*)(area->next) + diff);
		area->next->size -= diff;
	}
	return ptr;
}

void	*realloc_tiny(void *ptr, int size, t_area *area, t_page *page)
{
	void	*p;
	int		diff = size - area->size;
	int		tmp;
	
	if (diff > 0 && (!area->next || area->next->status == OCCUPIED || area->next->size + sizeof(t_area) < diff))
	{
		if (size + sizeof(t_area) <= TINYSIZE - sizeof(t_page))
			p = alloc_area(&g_pages.tiny, TINYSIZE, size));
		else if (size + sizeof(t_area) <= SMALLSIZE - sizeof(t_page))
			p = alloc_area(&g_pages.tiny, TINYSIZE, size);
		else
			p =  alloc_big(size);
		if (p)
		{
			ft_memcpy(p, ptr, area->size);
			free_area(g_pages.tiny, page, TINYSIZE, area);
		}
		return p;
	}
	else if (diff > 0 && area->next->size - diff < MINSIZE)
	{
		area->size += sizeof(t_area) + area->next->size;
		area->next = area->next->next;
	}
	else if (diff > 0)
	{
		area->size = size;
		ft_memcpy((byte*)(area->next) + diff, area->next, sizeof(t_area));
		area->next = (t_area*)((byte*)(area->next) + diff);
		area->next->size -= diff;
	}
	return ptr;
}

void	*realloc(void *ptr, size_t size)
{
	void	*p = NULL;
	t_big	*big;
	t_area	*area;
	t_page	*page;
	
	if (!ptr || !size)
	{
		free(ptr);
		return malloc(size);
	}
	size += size % MINSIZE > 0 ? MINSIZE - size % MINSIZE : 0;
	pthread_mutex_lock(&g_mutex);
	if (big = find_big(ptr))
		p = realloc_big(ptr, size, big);
	else if (area = find_small(ptr, &page))
		p = realloc_small(ptr, size, area, page);
	else if (area = find_tiny(ptr, &page))
		p = realloc_tiny(ptr, size, area, page);
	pthread_mutex_unlock(&g_mutex);
	return p;
}