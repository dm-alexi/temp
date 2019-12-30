#include "lemin.h"

typedef struct	s_queue
{
	t_node			*node;
	struct s_queue	*next;
}				t_queue;

static void		process(t_queue **q, t_queue **last)
{
	t_edge		*t;
	t_queue		*tmp;

	t = (*q)->node->edges;
	while (t)
	{
		if (t->node->distance < 0)
		{
			t->node->distance = (*q)->node->distance + t->len;
            if (!((*last)->next = (t_queue*)malloc(sizeof(t_queue))))
				sys_error();
			*last = (*last)->next;
			(*last)->node = t->node;
			(*last)->next = NULL;
		}
		t = t->next;
	}
	tmp = (*q)->next;
	free(*q);
	*q = tmp;
}

void			dijkstra(t_graph *graph)
{
	t_queue		*q;
	t_queue		*last;

	if (!(q = (t_queue*)malloc(sizeof(t_queue))))
		sys_error();
	q->node = graph->start;
	q->next = NULL;
	last = q;
	while (q)
		process(&q, &last);
	if ((graph->finish->distance) < 0)
		error();
}

//only undirected!!!
t_edge			*get_path(t_graph *graph)
{
    t_edge	*res;
    t_edge	*t;
    t_edge	*tmp;
    int		i;

    if ((i = graph->finish->distance) <= 0)
		return (NULL);
    if (!(res = (t_edge*)ft_memalloc(sizeof(t_edge))))
		sys_error();
	res->node = graph->finish;
	while (i)
	{
		t = res->node->edges;
		while (t->node->distance != i - 1)
			t = t->next;
        if (!(tmp = (t_edge*)malloc(sizeof(t_edge))))
			sys_error();
		tmp->node = t->node;
		tmp->next = res;
		res = tmp;
		--i;
	}
	return (res);
}
