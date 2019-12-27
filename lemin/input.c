#include <stdio.h>
#include "lem-in.h"
#define NODE 1
#define EDGE 2

static int		read_int(void)
{
	char	*line;
	int		tmp;
	int		n;

	while ((tmp = get_next_line(STDIN_FILENO, &line)) > 0 && *line == '#')
		free(line);
    if (tmp < 0)
		sys_error();
	else if (!tmp || (n = ft_atoi(line)) <= 0)
		error();
	free(line);
	return (n);
}

static int		get_line(char **line, t_command *com)
{
	int		tmp;

	*com = UNKNOWN;
	while ((tmp = get_next_line(STDIN_FILENO, line)) > 0 && **line == '#')
	{
		if (ft_strequ(*line, "##start"))
			*com = START;
		else if (ft_strequ(*line, "##end"))
			*com = END;
		else if (ft_strnequ(*line, "##", 2))
			*com = UNKNOWN;
		free(*line);
	}
	if (tmp <= 0)
		return (tmp);
	return (ft_strchr(*line, ' ') ? NODE : EDGE);
}

static int		compare(const void *a, const void *b)
{
	int		res;

	if (!(res = ft_strcmp((*((t_node**)a))->name, (*((t_node**)b))->name)))
		error();
	return (res);
}

static void		get_nodes(t_graph *graph, char **line)
{
	t_list		*lst;
	t_list		*tmp;
	t_command	com;
	int			i;

	lst = NULL;
	while ((i = get_line(line, &com)) == NODE && ++graph->node_num)
		ft_lstadd(&lst, new_node(*line, com));
	if (i <= 0)
		i ? sys_error() : error();
	if (!(graph->nodes = (t_node**)malloc(sizeof(t_node*) * graph->node_num)))
		sys_error();
	i = 0;
	while (lst)
	{
		tmp = lst->next;
		graph->nodes[i++] = lst->content;
		free(lst);
		lst = tmp;
	}
    ft_qsort(graph->nodes, graph->node_num, sizeof(t_node*), compare);
}

static void		get_edges(t_graph *graph, char **line)
{

}

t_graph			*get_graph(void)
{
	t_graph		*graph;
	char		*line;

	if (!(graph = (t_graph*)ft_memalloc(sizeof(t_graph))))
		sys_error();
	graph->ant_num = read_int();
	get_nodes(graph, &line);
	get_edges(graph, &line);
	return (graph);
}
