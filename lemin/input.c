#include "lem-in.h"
#define START 1
#define FINISH 2
#define NODE 4
#define EDGE 8

static int	get_line(char **line)
{
	int		tmp;

	if ((tmp = get_next_line(STDIN_FILENO, line)) <= 0)
		return (tmp);
	if (ft_strequ(*line, "##start"))
	{
		free(*line);
		if ((tmp = get_next_line(STDIN_FILENO, line)) <= 0)
			return (tmp);
		return (NODE | START);
	}
	if (ft_strequ(*line, "##end"))
	{
		free(*line);
		if ((tmp = get_next_line(STDIN_FILENO, line)) <= 0)
			return (tmp);
		return (NODE | FINISH);
	}
	return (ft_strchr(*line, ' ') ? NODE : EDGE);
}

t_graph		*get_graph()
{
	t_graph		*graph;
	char		*line;
	int			route_set;
	int			tmp;

	route_set = 0;
	if (!(graph = (t_graph*)ft_memalloc(sizeof(t_graph))))
		sys_error();
	while ((tmp = get_line(&line)))
	{
		if (tmp < 0)
			sys_error();

	}
}
