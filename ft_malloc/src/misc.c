/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:14:47 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/21 22:35:09 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_memcpy(void *dst, void *src, size_t num)
{
	size_t	*d = dst;
	size_t	*s = src;

	if (d != s)
		for (size_t i = 0; i < num; i += sizeof(size_t))
			*d++ = *s++;
}

void	*find_big(void *ptr)
{
	for (t_big *big = g_pages->big; big; big = big->next)
		if (big == (t_big*)((byte*)ptr - sizeof(t_big)))
			return big;
	return NULL;
}

void	*find_tiny(void *ptr, t_page **p)
{
	t_area	*area;

	for (page = g_pages->tiny; page && (ptr < page || ptr > page + TINYSIZE); page = page->next);
	if (page)
		for (area = (t_area*)((byte*)page + sizeof(t_page)); area && area <= (t_area*)((byte*)ptr - sizeof(t_area)); area = area->next)
			if (area == (t_area*)((byte*)ptr - sizeof(t_area)) && area->status == OCCUPIED && (*p = page))
				return area;
	return NULL;
}

void	*find_small(void *ptr, t_page **p)
{
	t_area	*area;

	for (page = g_pages->small; page && (ptr < page || ptr > page + SMALLSIZE); page = page->next);
	if (page)
		for (area = (t_area*)((byte*)page + sizeof(t_page)); area && area <= (t_area*)((byte*)ptr - sizeof(t_area)); area = area->next)
			if (area == (t_area*)((byte*)ptr - sizeof(t_area)) && area->status == OCCUPIED && (*p = page))
				return area;
	return NULL;
}