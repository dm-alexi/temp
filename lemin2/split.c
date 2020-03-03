/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:15:41 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/03 15:57:46 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_node	*split(t_graph *graph, t_node *node, t_edge *prev, t_edge *next)
{
	t_node	*out;

	if (!(out = (t_node*)ft_memalloc(sizeof(t_node))))
		sys_error();
	graph->nodes[graph->node_num++] = out;
	out->name = ft_strjoin(node->name, "-out");
	out->type = TEMP;
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

void			split_path(t_graph *graph, t_edge *path)
{
	t_edge	*prev;

	prev = find(path->node, path->next->node->edges);
	remove_edge(path->next->node, &(path->node->edges));
	path = path->next;
	while (path->next)
	{
		remove_edge(path->next->node, &(path->node->edges));
		prev = find(split(graph, path->node, prev,
		find(path->node, path->next->node->edges)), path->next->node->edges);
		path = path->next;
	}
}

void			split_paths(t_graph *graph)
{
	int	i;

	i = -1;
	while (++i < graph->path_num)
		split_path(graph, graph->paths[i]);
}

static void		restore_edges(t_graph *graph)
{
	int		i;
	t_edge	*t;
	t_edge	*s;

	i = -1;
	while (++i < graph->node_num)
	{
		s = graph->backup[i];
		t = (t_edge*)ft_memalloc(sizeof(t_edge));
		graph->nodes[i]->edges = t;
		t->len = 1;
		t->node = s->node;
		while (s->next)
		{
			t->next = (t_edge*)ft_memalloc(sizeof(t_edge));
			t->next->len = 1;
			t->next->node = s->next->node;
			t = t->next;
			s = s->next;
		}
		t->next = NULL;
	}
}

void			restore_graph(t_graph *graph)
{
	int	i;

	while (graph->nodes[graph->node_num - 1]->type == TEMP)
	{
		delete_path(graph->nodes[--graph->node_num]->edges);
		free(graph->nodes[graph->node_num]->name);
		free(graph->nodes[graph->node_num]);
	}
	i = -1;
	while (++i < graph->node_num)
		delete_path(graph->nodes[i]->edges);
	restore_edges(graph);
}
