/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:35:59 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/19 21:50:24 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

g_mutex = PTHREAD_MUTEX_INITIALIZER;
g_pages = (t_pages){NULL, NULL};

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

void	*alloc_big(size_t size)
{
	void	*ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);

	if (ptr == MAP_FAILED)
		return NULL;
	return ptr;
}

void	*alloc_tiny(size_t size)
{
	t_mempage	*page;
	void		*ptr;

	for (page = g_pages.tiny; page; page = page->next)
	{
		t_area	*area = page->vacant;
		while (area && area->size < size)
			area = area->next;
		if (area)
		{
			ptr = (t_byte *)area + sizeof(t_area);
		}
	}
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	if (!size)
		return NULL;
	size += size % MINSIZE ? MINSIZE - size % MINSIZE : 0;
	pthread_mutex_lock(&g_mutex);
	if (size + sizeof(t_area) <= TINYSIZE - sizeof(t_mempage))
		ptr = alloc_tiny(size + sizeof(t_area));
	else if (size + sizeof(t_area) <= SMALLSIZE - sizeof(t_mempage))
		ptr = alloc_small(size + sizeof(t_area));
	else ptr = alloc_big(size);
	pthread_mutex_lock(&g_mutex);
	return ptr;
}

