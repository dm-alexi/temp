#include "lemin.h"

void	distribute(t_graph *graph)
{
	int		i;
	int		s;
	t_edge	*t;

	if (!(graph->path_len = (int*)ft_memalloc(sizeof(int) * graph->path_num)) ||
	!(graph->ants = (int*)malloc(sizeof(int) * graph->path_num)))
		sys_error();
    i = -1;
    s = 0;
    while (++i < graph->path_num)
	{
		t = graph->paths[i];
		while (t->node->type != FINISH)
		{
            t->len = 0;
            t = t->next;
            ++graph->path_len[i];
		}
		s += graph->path_len[i];
	}
	for (i = 0; i < graph->path_num; ++i)
		ft_printf("%d ", graph->path_len[i]);
	ft_printf("\n");
	i = -1;
	while (++i < graph->path_num)
		graph->ants[i] = graph->moves - graph->path_len[i] +
		(i < graph->path_num - (graph->ant_num + s) % graph->path_num);
	for (i = 0; i < graph->path_num; ++i)
		ft_printf("%d ", graph->ants[i]);
}
