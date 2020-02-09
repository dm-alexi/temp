#include "lemin.h"

//free intermediate nodes here!
int		resolve_conflict(t_edge *p1, t_edge *p2)
{
	t_edge	*t2s;
    t_edge	*t2f;
    t_edge	*tmp;
    int		r1;
    int		r2;

    if (p1->next->node->type == FINISH || p2->next->node->type == FINISH)
		return (0);
	r1 = p1->next->node->rank;
	r2 = p2->next->node->rank;
    t2s = p2->next;
    while (t2s->node->rank != r1 && t2s->node->type != FINISH)
		t2s = t2s->next;
	if (t2s->node->type == FINISH)
		return (0);
	t2f = t2s->next;
	while (t2f->next->node->rank == r1)
		t2f = t2f->next;
	while (p1->node != t2f->node)
		p1 = p1->next;
    tmp = p1->next;
    p1->next = t2f->next;
    while (tmp->node != t2s->node)
		tmp = tmp->next;
	t2s->next = tmp->next;
	return (1);
}

void	solve(t_graph *graph)
{
    t_edge	**new_paths;
    int		i;

    while (graph->path_num < graph->path_max)
	{
		new_paths = clone(graph->paths, graph->path_num);
		i = 0;
		while (i < graph->path_num)
			path_reverse(graph, graph->paths[i++]);
		belford(graph);
		new_paths[graph->path_num] = get_path(graph);
		while (--i >= 0)
			path_restore(graph, graph->paths[i]);
        print_graph(graph);
        for (int i = 0; i <= graph->path_num; ++i)
			print_path(new_paths[i]);
		resolve_conflict(new_paths[0], new_paths[1]);
		print_graph(graph);
        for (int i = 0; i <= graph->path_num; ++i)
			print_path(new_paths[i]);
		break;
	}
}
