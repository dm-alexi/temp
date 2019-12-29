/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:25:49 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/29 17:20:53 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lemin.h"

static int		read_int(void)
{
	char	*line;
	int		tmp;
	int		n;

	while ((tmp = get_next_line(STDIN_FILENO, &line)) > 0 && *line == '#')
	{
		ft_printf("%s\n", line);
		free(line);
	}
	if (tmp <= 0)
		tmp ? sys_error() : error();
	if (((n = ft_atoi(line))) <= 0)
		error();
	ft_printf("%s\n", line);
	free(line);
	return (n);
}

static void		finalize(t_graph *graph)
{
	int		i;

	i = 0;
	while (i < graph->node_num)
	{
		if (--graph->nodes[i]->distance == 0)
			graph->start = graph->nodes[i];
		else if (graph->nodes[i]->distance == 1)
		{
			graph->finish = graph->nodes[i];
			graph->nodes[i]->distance = -1;
		}
		++i;
	}
	if (!graph->start || !graph->finish)
		error();
}

int		get_line(char **line, t_command *com)
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
		ft_printf("%s\n", *line);
		free(*line);
	}
	if (tmp <= 0)
		return (tmp);
	ft_printf("%s\n", *line);
	return (ft_strchr(*line, ' ') ? NODE : EDGE);
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
	ft_printf("\n");
	finalize(graph);
	return (graph);
}
