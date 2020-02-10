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

void		resolve_conflicts(t_edge **paths, int n)
{
	int		i;
	int		j;
	t_edge	*tmp;

	i = 0;
	while (i < n - 1)
	{
		if (resolve_conflict(paths[i], paths[n - 1]))
		{
			tmp = paths[i];
			paths[i] = paths[n - 1];
			paths[n - 1] = tmp;
			set_rank(paths[n - 1], 0);
			j = -1;
			while (++j < n - 1)
				set_rank(paths[j], j + 1);
			resolve_conflicts(paths, n);
			return ;
		}
		++i;
	}
}

int		path_len(t_edge *path)
{
	int		n;

	n = 0;
	while ((path = path->next))
		++n;
	return (n);
}

int		count_moves(t_edge **paths, int n_paths, int ants)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (i < n_paths)
		n += path_len(paths[i++]);
	return ((ants - n_paths + n) / n_paths + ((ants + n) % n_paths > 0));
}

void	solve(t_graph *graph)
{
    t_edge	**new_paths;
    int		i;
    int		c;

    while (graph->path_num < graph->path_max)
	{
		reset_distance(graph);
		set_ranks(graph);
		new_paths = clone(graph->paths, graph->path_num);
		i = 0;
		while (i < graph->path_num)
			path_reverse(graph, graph->paths[i++]);
		belford(graph);
		new_paths[graph->path_num] = get_path(graph);
		while (--i >= 0)
			path_restore(graph, graph->paths[i]);
		resolve_conflicts(new_paths, graph->path_num + 1);
		if ((c = count_moves(new_paths, graph->path_num + 1, graph->ant_num))
			>= graph->moves)
		{
            delete_paths(new_paths, graph->path_num + 1);
            print_graph(graph);
            return ;
		}
		delete_paths(graph->paths, graph->path_num);
		graph->paths = new_paths;
		++graph->path_num;
		graph->moves = c;
		print_graph(graph);
	}
}
