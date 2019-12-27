#include "lem-in.h"

t_list	*new_node(char *line, t_command com)
{
	char	*s;
	t_node	node;

	if (!(s = ft_strrchr(line, ' ')))
        error();
    node.y = ft_atoi(s);
    *s = '\0';
    if (!(s = ft_strrchr(line, ' ')))
        error();
	node.x = ft_atoi(s);
	*s = '\0';
    if (!*line)
		error();
	node.name = ft_strdup(line);
	node.nodes = NULL;
	node.distance = com;
	free(line);
	return (ft_lstnew(&node, sizeof(t_node)));
}

static int	compare(const void *a, const void *b)
{
	int		res;

	if (!(res = ft_strcmp((*((t_node**)a))->name, (*((t_node**)b))->name)))
		error();
	return (res);
}

void	include_nodes(t_graph *graph, t_list *lst)
{
	t_list	*tmp;
	int		i;

	if (!(graph->nodes = (t_node**)malloc(sizeof(t_node*) * graph->node_num)))
		sys_error();
	i = 0;
	while (lst)
	{
		tmp = lst->next;
		graph->nodes[i++] = lst->content;
		ft_printf("%s\n", graph->nodes[i - 1]->name);
		free(lst);
		lst = tmp;
	}
    ft_qsort(graph->nodes, graph->node_num, sizeof(t_node*), compare);
}
