#include "lemin.h"

void	resolve_conflict(t_edge *p1, t_edge *p2)
{

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

		break;
	}
}
