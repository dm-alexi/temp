#include "lem-in.h"
#define START 1
#define FINISH 2
#define NODE 4
#define EDGE 8

//rewrite it all!

static int	unknown(char *line)
{
	return !(ft_strequ(line, "##start") || ft_strequ(line, "##end"));
}

static int get_command(char **line)
{
    int		res;
    int		tmp;

    res = -1;
    if (ft_strequ(*line, "##start"))
		res = START;
	else if (ft_strequ(*line, "##end"))
		res = FINISH;
	free(*line);
	while ((tmp = get_next_line(STDIN_FILENO, line)) > 0 && **line == '#' &&
		(!ft_strnequ(*line, "##", 2) || unknown(*line)))
			free(*line);
	if (tmp <= 0)
		return (tmp);
	if (ft_strnequ(*line, "##", 2))
		return (get_command(line));
	return (res | NODE);
}

static int	get_line(char **line)
{
	int		tmp;
	int		res;

	while ((tmp = get_next_line(STDIN_FILENO, line)) > 0 && **line == '#' &&
		(!ft_strnequ(*line, "##", 2) || unknown(*line)))
			free(*line);
	if (tmp <= 0)
		return (tmp);
	if (ft_strnequ(*line, "##", 2))
		return (get_command(line));
	return (ft_strchr(*line, ' ') ? NODE : EDGE);
}

t_graph		*get_graph()
{
	t_graph		*graph;
	char		*line;
	int			tmp;

	if (!(graph = (t_graph*)ft_memalloc(sizeof(t_graph))))
		sys_error();
	while ((tmp = get_line(&line)))
	{
		if (tmp < 0)
			sys_error();
		if (tmp & NODE)
			add_node(graph, tmp, line);
		else if (tmp & EDGE)
			add_edge(graph, tmp, line);
	}
	return (graph);
}
