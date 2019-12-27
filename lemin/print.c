#include "lem-in.h"

void	print_graph(t_graph *graph)
{
	int 	i;

	ft_printf("--------------------\nNumber of ants: %d\nNodes:\n", graph->ant_num);
	i = -1;
    while (++i < graph->node_num)
		ft_printf("%s\t\t%d %d\n", graph->nodes[i]->name, graph->nodes[i]->x, graph->nodes[i]->y);
	ft_printf("--------------------\n");
}

/*
void print_node(const t_node *a)
{
	ft_printf("Name: %s, x = %d, y = %d\n", a->name, a->x, a->y);
}
*/
