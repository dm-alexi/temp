/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:35:44 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/21 22:11:01 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/mman.h>
#include "ft_malloc.h"

void	free_big(t_big *big)
{
	if (big->prev)
		big->prev->next = big->next;
	if (big->next)
		big->next->prev = big->prev;
	if (big == g_pages.big)
		g_pages.big = big->next;
	munmap(big, big->size + sizeof(t_big));
}

void	free_area(t_page *first, t_page *page, int size, t_area *area)
{
	area->status = VACANT;
	if (area->next && area->next->status == VACANT)
	{
		area->size += area->next->size + sizeof(t_area)
		area->next = area->next->next;
	}
	if (area->prev && area->prev->status == VACANT)
	{
		area->prev->size += area->size + sizeof(area);
		area->prev->next = area->next;
		area = area->prev;
	}
	if (!area->prev && !area->next)
	{
		if (page == first)
			*first = page->next;
		if (page->prev)
			page->prev->next = page->next;
		if (page->next)
			page->next->prev = page->prev;
		munmap(page, size)
	}
}

// int	free_regular(t_page *first, int size, void *ptr)
// {
// 	t_page	*page;
// 	t_area	*area;
	
// 	for (page = *first; page && (ptr < page || ptr > page + size); page = page->next);
// 	if (page)
// 		for (area = (t_area*)((byte*)page + sizeof(t_page)); area && area <= (t_area*)((byte*)ptr - sizeof(t_area)); area = area->next)
// 			if (area == (t_area*)((byte*)ptr - sizeof(t_area)))
// 			{
// 				free_area(first, page, size, area);
// 				return 0;
// 			}
// 	return 1;
// }

void	free(void *ptr)
{
	t_page	*page;
	t_area	*area;
	t_big	*big;

	if (!ptr)
		return;
	pthread_mutex_lock(&g_mutex);
	if (big = find_big(ptr))
		free_big(big);
	else if (area = find_small(ptr, &page))
		free_area(g_pages.small, page, SMALLSIZE, area);
	else if (area = find_tiny(ptr, &page))
		free_area(g_pages.tiny, page, TINYSIZE, area);
	pthread_mutex_unlock(&g_mutex);
}