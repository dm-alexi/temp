/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belford.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:30:09 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/08 18:39:27 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	reset_distance(t_graph *graph)
{
	int		i;

	i = 0;
	while (i < graph->node_num)
		graph->nodes[i++]->distance = -1;
	graph->start->distance = 0;
}

void	belford(t_graph *graph)
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
			while (t)
			{
				if (graph->nodes[j]->distance != -1 && (t->node->distance == -1
				|| t->node->distance > graph->nodes[j]->distance + t->len))
				{
					t->node->distance = graph->nodes[j]->distance + t->len;
					t->node->prev = graph->nodes[j];
					fin = 0;
				}
				t = t->next;
			}
	}
}
