/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:21:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/25 19:22:00 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		cover(col *c)
{
	node	*v;
	node	*h;

	c->prev->next = c->next;
	c->next->prev = c->prev;
	v = c->head.d;
	while (v != &(c->head))
	{
		h = v->r;
		while (h != v)
		{
			h->u->d = h->d;
			h->d->u = h->u;
			h->column->size--;
			h = h->r;
		}
		v = v->d;
	}
}

static void		cover_all(node *c)
{
	node	*t;

	cover(c->column);
	t = c->r;
	while (t != c)
	{
		cover(t->column);
		t = t->r;
	}
}

static void		uncover(col *c)
{
	node	*v;
	node	*h;

	v = c->head.u;
	while (v != &(c->head))
	{
		h = v->l;
		while (h != v)
		{
			h->u->d = h;
			h->d->u = h;
			h->column->size++;
			h = h->l;
		}
		v = v->u;
	}
	c->prev->next = c;
	c->next->prev = c;
}

static void		uncover_all(node *c)
{
	node	*t;

	t = c->l;
	while (t != c)
	{
		uncover(t->column);
		t = t->l;
	}
	uncover(c->column);
}

node	**solve(col *arr, int n)
{
	static node		*solution[26];
	static int		k;
	col				*current;
	node			*t;

	current = arr[0].next;
	if (current == arr)
		return (solution);
	t = current->head.d;
	while (t != &(current->head))
	{
		solution[k++] = t;
		cover_all(t);
		if (solve(arr, n))
			return (solution);
		uncover_all(t);
		--k;
		t = t->d;
	}
	//for (int i = 1; i <= n + 16; ++i)
	//	printf("%d %s %d\n", i, arr[i].name, arr[i].size);
	return (NULL);
}
