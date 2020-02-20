/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belford.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:30:09 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/20 22:40:53 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			reset_distance(t_graph *graph)
{
	int		i;

	i = 0;
	while (i < graph->node_num)
		graph->nodes[i++]->distance = -1;
	graph->start->distance = 0;
}

static void		update(t_node *from, t_edge *edge, int *fin)
{
	if ((edge->node->distance == -1 ||
	edge->node->distance > from->distance + edge->len) &&
	(edge->node->rank == from->rank || from->rank == from->prev->rank))
	{
		edge->node->distance = from->distance + edge->len;
		edge->node->prev = from;
		*fin = 0;
	}
}

void			belford(t_graph *graph)
{
	int		i;
	int		j;
	int		fin;
	t_edge	*t;

	reset_distance(graph);
	i = graph->node_num - 1;
	fin = 0;
	while (i-- && !fin)
	{
		j = -1;
		fin = 1;
		while (++j < graph->node_num && (t = graph->nodes[j]->edges))
			if (graph->nodes[j]->distance != -1 &&
			graph->nodes[j]->type != FINISH)
				while (t)
				{
					update(graph->nodes[j], t, &fin);
					t = t->next;
				}
	}
}
