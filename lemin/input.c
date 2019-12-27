#include <stdio.h>
#include "lem-in.h"
#define NODE 1
#define EDGE 2

static int	read_int(void)
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

static int	get_line(char **line, t_command *com)
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

t_graph		*get_graph(void)
{
	t_graph		*graph;
	char		*line;
	int			tmp;
	t_command	com;
	t_list		*lst;

	if (!(graph = (t_graph*)ft_memalloc(sizeof(t_graph))))
		sys_error();
	lst = NULL;
	graph->ant_num = read_int();
	while ((tmp = get_line(&line, &com)) == NODE && ++graph->node_num)
		ft_lstadd(&lst, new_node(line, com));
	if (tmp < 0)
		sys_error();
	include_nodes(graph, lst);
	return (graph);
}
