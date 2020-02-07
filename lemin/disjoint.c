#include "lemin.h"

static t_edge *find(t_node *node, t_edge *edge)
{
	while (edge->node && edge->node != node)
		edge = edge->next;
	return (edge);
}

static void remove_edge(t_node *node, t_edge **edge)
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

void split(t_graph *graph, t_node *node, t_edge *in)
{
	t_node	*out;

	if (!(out = (t_node*)ft_memalloc(sizeof(t_node))))
		sys_error();
	graph->nodes[graph->node_num++] = out;
	out->name = ft_strjoin(node->name, "-out");
	in->node = out;
	in->len = -1;
	out->edges = node->edges;
	if (!(node->edges = (t_edge*)ft_memalloc(sizeof(t_edge))))
		sys_error();
    node->edges->node = prev->node;
    node->edges->len = -1;
    node->edges->next = NULL;
    prev->node = node;
}

void path_reverse(t_edge *path)
{
	while (path->next)
	{
		remove_edge(path->next->node, &(path->node->edges));
		find(path->node, path->next->node->edges)->len = -1;
		path = path->next;
	}
}

void path_split(t_graph *graph, t_edge *path)
{
    path = path->next;
    while (path->next)
	{
		ft_printf("Now splitting: %s\n", path->node->name);
		split(graph, path->node, find(path->node, path->next->node->edges));
		path = path->next;
	}
}
