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
	int		res;

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

t_graph		*get_graph()
{
	t_graph		*graph;
	char		*line;
	int			tmp;
	t_command	com;

	if (!(graph = (t_graph*)ft_memalloc(sizeof(t_graph))))
		sys_error();
	graph->antnum = read_int();
	while ((tmp = get_line(&line, &com)))
	{
		if (tmp < 0)
			sys_error();
		if (tmp == NODE)
			add_node(graph, com, line);
		else if (tmp == EDGE)
			add_edge(graph, com, line);
		free(line);
	}
	return (graph);
}
