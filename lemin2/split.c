#include "lemin.h"

static void		remove_edge(t_node *node, t_edge **edge)
{
	t_edge	*t;
	t_edge	*tmp;
	if ((t = (*edge))->node == node)
	{
		*edge = (*edge)->next;
		free(t);
	}
	else
	{
		while (t->next->node != node)
			t = t->next;
		tmp = t->next;
		t->next = t->next->next;
		free(tmp);
	}
}

static t_node *split(t_graph *graph, t_node *node, t_edge *prev, t_edge *next)
{
	t_node	*out;

	if (!(out = (t_node*)ft_memalloc(sizeof(t_node))))
		sys_error();
	graph->nodes[graph->node_num++] = out;
	out->name = ft_strjoin(node->name, "-out");
	out->type = UNKNOWN;
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

void split_path(t_graph *graph, t_edge *path)
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

void backup_edges(t_graph *graph)
{
	int	i;
	t_edge	*t;
	t_edge	*s;

	i = -1;
	while (++i < graph->node_num)
	{
		s = graph->nodes[i]->edges;
		t = (t_edge*)malloc(sizeof(t_edge));
		graph->backup[i] = t;
		t->len = 1;
		t->node = s->node;
		while (s->next)
		{
			t->next = (t_edge*)malloc(sizeof(t_edge));
			t->next->len = 1;
			t->next->node = s->next->node;
			t = t->next;
			s = s->next;
		}
		t->next = NULL;
	}
}

void split_paths(t_graph *graph)
{
	int	i;

	backup_edges(graph);
	i = -1;
	print_paths(graph->paths, graph->path_num);
	while (++i < graph->path_num)
	{
		//print_path(graph->paths[i]);
		split_path(graph, graph->paths[i]);
		//ft_printf(" - %d success\n", i);
	}
}

void restore_graph(t_graph *graph)
{
	int	i;

	while (ft_strchr(graph->nodes[graph->node_num - 1]->name, '-'))
	{
		delete_path(graph->nodes[--graph->node_num]->edges);
		free(graph->nodes[graph->node_num]);
	}
	i = -1;
	while (++i < graph->node_num)
	{
		delete_path(graph->nodes[i]->edges);
		graph->nodes[i]->edges = graph->backup[i];
	}
}
