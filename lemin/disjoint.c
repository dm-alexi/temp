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

void path_reverse(t_edge *path)
{
	while (path->next)
	{
		remove_edge(path->next->node, &(path->node->edges));
		find(path->node, path->next->node->edges)->len = -1;
		path = path->next;
	}
}

void split(t_graph *graph, t_node *node, t_node *next)
{
	t_node	*out;
	t_edge	*in;

	out = (*graph->nodes) + graph->node_num++;
	out->name = ft_strjoin(node->name, "-out");
	in = find(node, next->edges);
	in->len = -1;
	in->node = out;
	out->edges = node->edges;
	if (!(node->edges = (t_edge*)ft_memalloc(sizeof(t_edge))))
		sys_error();
    node->edges->node = out;
}
