/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:35:44 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/21 00:32:35 by sscarecr         ###   ########.fr       */
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
	munmap(big, big->size + sizeof(t_big));
}

void	free_area(t_area *area, t_page *page, int size)
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
		
	}
}

void	ft_free(void *ptr)
{
	t_page	*page;
	t_area	*area;

	if (!ptr)
		return;
	for (t_big *big = g_pages->big; big; big = big->next)
		if (big == (t_big*)((byte*)ptr - sizeof(t_big)))
		{
			free_big(big);
			return;
		}
	for (page = g_pages->small; page && (ptr < page || ptr > page + SMALLSIZE); page = page->next);
	if (page)
		for (area = (t_area*)((byte*)page + sizeof(t_page)); area && area <= (t_area*)((byte*)ptr - sizeof(t_area)); area = area->next)
			if (area == (t_area*)((byte*)ptr - sizeof(t_area)))
			{
				free_area(area, page, SMALLSIZE);
				return ;
			}
	for (page = g_pages->tiny; page && (ptr < page || ptr > page + TINYSIZE); page = page->next);
	if (page)
		for (area = (t_area*)((byte*)page + sizeof(t_page)); area && area <= (t_area*)((byte*)ptr - sizeof(t_area)); area = area->next)
			if (area == (t_area*)((byte*)ptr - sizeof(t_area)))
			{
				free_area(area, page, TINYSIZE);
				return ;
			}
}