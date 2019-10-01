/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:21:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/01 20:41:55 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		cover(t_col *c)
{
	t_node	*v;
	t_node	*h;

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

static void		cover_all(t_node *c)
{
	t_node	*t;

	cover(c->column);
	t = c->r;
	while (t != c)
	{
		cover(t->column);
		t = t->r;
	}
}

static void		uncover(t_col *c)
{
	t_node	*v;
	t_node	*h;

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

static void		uncover_all(t_node *c)
{
	t_node	*t;

	t = c->l;
	while (t != c)
	{
		uncover(t->column);
		t = t->l;
	}
	uncover(c->column);
}

t_node			**solve(t_col *arr, int n)
{
	static t_node	*solution[26];
	static int		k;
	t_col			*current;
	t_node			*t;

	current = arr[0].next;
	if (current == arr)
		return (solution);
	t = current->head.d;
	while (t != &(current->head))
	{
		solution[k++] = t;
		cover_all(t);
		solve(arr, n);
		uncover_all(t);
		if (k == n)
			break ;
		--k;
		t = t->d;
	}
	return (k == n ? solution : NULL);
}
