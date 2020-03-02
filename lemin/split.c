/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:49:33 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/02 19:50:49 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_node *split(t_graph *graph, t_node *node, t_edge *prev, t_edge *next)
{
	t_node	*out;

	if (!(out = (t_node*)ft_memalloc(sizeof(t_node))))
		sys_error();
	graph->nodes[graph->node_num++] = out;
	out->name = ft_strjoin(node->name, "-out");
    next->node = out;
    next->len = -1;
    out->edges = node->edges;
    if (!(node->edges = (t_edge*)ft_memalloc(sizeof(t_edge))))
		sys_error();
	node->edges->node = prev->node;
	node->edges->len = -1;
	prev->node = node;
	prev->len = 0;
	return (out);
}

void path_split(t_graph *graph, t_edge *path)
{
    t_edge *prev = find(path->node, path->next->node->edges);
    t_edge	*prev;

	prev = find(path->node, path->next->node->edges);
    remove_edge(path->next->node, &(path->node->edges));
    path = path->next;
    while (path->next)
	{
		prev = find(split(graph, path->node, prev, find(path->node, path->next->node->edges)), path->next->node->edges);
		remove_edge(path->next->node, &(path->node->edges));
		prev = find(split(graph, path->node, prev,
		find(path->node, path->next->node->edges)), path->next->node->edges);
		path = path->next;
	}
}