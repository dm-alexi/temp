/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:30:18 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/10 20:04:22 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		process(t_queue **q, t_queue **last)
{
	t_edge		*t;
	t_queue		*tmp;

	t = (*q)->node->edges;
	while (t)
	{
		if (t->node->distance < 0)
		{
			t->node->distance = (*q)->node->distance + t->len;
			t->node->prev = (*q)->node;
			if (!((*last)->next = (t_queue*)malloc(sizeof(t_queue))))
				sys_error();
			*last = (*last)->next;
			(*last)->node = t->node;
			(*last)->next = NULL;
		}
		t = t->next;
	}
	tmp = (*q)->next;
	free(*q);
	*q = tmp;
}

void			bfs(t_graph *graph)
{
	t_queue		*q;
	t_queue		*last;

	if (!(q = (t_queue*)malloc(sizeof(t_queue))))
		sys_error();
	q->node = graph->start;
	q->next = NULL;
	last = q;
	while (q)
		process(&q, &last);
	if ((graph->finish->distance) < 0)
		error();
	graph->moves = graph->ant_num - 1 + graph->finish->distance;
	graph->path_num = 1;
	graph->paths[0] = get_path(graph);
	set_rank(graph->paths[0], 1);
}

t_edge			*get_path(t_graph *graph)
{
	t_edge	*res;
	t_edge	*tmp;
	int		i;

	if ((i = graph->finish->distance) <= 0)
		return (NULL);
	if (!(res = (t_edge*)ft_memalloc(sizeof(t_edge))))
		sys_error();
	res->node = graph->finish;
	while (res->node->prev)
	{
		if (!(tmp = (t_edge*)malloc(sizeof(t_edge))))
			sys_error();
		tmp->node = res->node->prev;
		tmp->next = res;
		res = tmp;
	}
	return (res);
}

void			set_rank(t_edge *path, int rank)
{
	while ((path = path->next)->node->type != FINISH)
		path->node->rank = rank;
}

void			set_ranks(t_graph *graph)
{
	int		i;

	i = 0;
	while (i < graph->path_num)
	{
		set_rank(graph->paths[i], i + 1);
		++i;
	}
}
