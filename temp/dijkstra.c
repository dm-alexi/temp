/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:57:24 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/14 20:59:18 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

typedef struct	s_elem
{
	t_node	*from;
	t_node	*to;
	int		dist;
}				t_elem;

typedef struct	s_heap
{
	t_elem	*t;
	int		num;
}				t_heap;

static void		heapify(t_heap *h, int i)
{
	int		left;
	int		right;
	int		smallest;

	left = 2 * i + 1;
	right = left + 1;
	smallest = i;
	if (left < h->num && h->t[left].dist < h->t[smallest].dist)
		smallest = left;
	if (right < h->num && h->t[right].dist < h->t[smallest].dist)
		smallest = right;
	if (smallest != i)
	{
		ft_memswap(&h->t[smallest], &h->t[i], sizeof(t_elem));
		heapify(h, smallest);
	}
}

static void		put(t_heap *h, t_node *from, t_node *to, int dist)
{
	int		k;

	k = h->num++;
	h->t[k].dist = dist;
	h->t[k].from = from;
	h->t[k].to = to;
	while (k && h->t[k].dist < h->t[(k - 1) / 2].dist)
	{
		ft_memswap(&h->t[k], &h->t[(k - 1) / 2], sizeof(t_elem));
		k = (k - 1) / 2;
	}
}

static void		put_node(t_heap *h, t_node *node)
{
	t_edge	*t;

	t = node->edges;
	while (t)
	{
		if (t->node->distance < 0)
			put(h, node, t->node, node->distance + t->len);
		t = t->next;
	}
}

static t_elem	get(t_heap *h)
{
	t_elem	tmp;

	tmp = h->t[0];
	h->t[0] = h->t[--h->num];
	heapify(h, 0);
	return (tmp);
}

void			dijkstra(t_graph *graph)
{
	t_heap	h;
	t_elem	tmp;

	reset_distance(graph);
	h.num = 0;
	if (!(h.t = (t_elem*)malloc(sizeof(t_elem) *
	((graph->node_num - 1) * (graph->node_num - 2) / 2 + 1))))
		sys_error();
	put_node(&h, graph->start);
	while (h.num && graph->finish->distance < 0)
	{
		tmp = get(&h);
		if (tmp.to->distance < 0 && (tmp.from->rank == tmp.to->rank ||
		tmp.from->rank == tmp.from->prev->rank))
		{
			tmp.to->distance = tmp.dist;
			tmp.to->prev = tmp.from;
			put_node(&h, tmp.to);
		}
	}
	free(h.t);
}
