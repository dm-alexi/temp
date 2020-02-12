#include "lemin.h"

static void		setup(t_graph *graph)
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
	i = -1;
	while (++i < graph->path_num)
		graph->ants[i] = graph->moves - graph->path_len[i] +
		(i < graph->path_num - (graph->ant_num + s) % graph->path_num);
}

static int		send_ants(t_graph *graph, int sent)
{
    int		i;
    int		j;

    i = -1;
    j = 0;
    while (++i < graph->path_num && sent + j < graph->ant_num)
        if (graph->ants[i] && --graph->ants[i] && ++j)
            graph->paths[i]->len = j;
	return (sent + j);
}

static void		promote_ants(t_graph *graph)
{
	t_edge	*t;
	int		tmp;

	for (int i = 0; i < graph->path_num; ++i)
	{
        t = graph->paths[i];
        //tmp = t->next->len;
        while (t->next)
		{
			tmp = t->next->len;
			if (tmp)
				ft_printf("L%d-%s ", t->next->len, t->next->node->name);
			t->next->len = t->len;
			t = t->next;
		}
	}
}

void	distribute(t_graph *graph)
{
	int		sent;

	setup(graph);
	for (int i = 0; i < graph->path_num; ++i)
		ft_printf("%d ", graph->path_len[i]);
	ft_printf("\n");
	for (int i = 0; i < graph->path_num; ++i)
		ft_printf("%d ", graph->ants[i]);
	sent = send_ants(graph, 0);
	for (int i = 0; i < graph->moves; ++i)
	{
		promote_ants(graph);
		ft_printf("\n");
		if (sent < graph->ant_num)
			sent = send_ants(graph, sent);
	}
}
