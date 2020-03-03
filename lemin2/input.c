/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:25:49 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/03 15:11:27 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef _WIN32
# include <stdio.h>
#else
# include <unistd.h>
#endif
#include <limits.h>
#include "lemin.h"

static int		read_int(void)
{
	char	*line;
	char	*t;
	int		tmp;
	long	n;

	while ((tmp = get_next_line(STDIN_FILENO, &line)) > 0 && *line == '#')
	{
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
			error();
		ft_printf("%s\n", line);
		free(line);
	}
	if (tmp <= 0)
		tmp ? sys_error() : error();
	if (!(*(t = line)))
		error();
	while (*t)
		if (!ft_isdigit(*t++))
			error();
	if ((n = ft_strtol(line, NULL, 10)) <= 0 || n > INT_MAX)
		error();
	ft_printf("%s\n", line);
	free(line);
	return ((int)n);
}

static int		path_count(t_graph *graph)
{
	int		count;
	int		i;
	t_edge	*t;

	count = graph->ant_num;
	t = graph->start->edges;
	i = 0;
	while (t && ++i)
		t = t->next;
	if (i < count)
		count = i;
	t = graph->finish->edges;
	i = 0;
	while (t && ++i)
		t = t->next;
	if (i < count)
		count = i;
	return (count);
}

static void		finalize(t_graph *graph)
{
	int		i;

	i = -1;
	while (++i < graph->node_num)
		if (graph->nodes[i]->type == START)
		{
			if (graph->start)
				error();
			graph->start = graph->nodes[i];
		}
		else if (graph->nodes[i]->type == FINISH)
		{
			if (graph->finish)
				error();
			graph->finish = graph->nodes[i];
		}
	if (!graph->start || !graph->finish ||
	!(graph->path_max = path_count(graph)))
		error();
	if (!(graph->paths = (t_edge**)ft_memalloc(sizeof(t_edge*))) ||
	!(graph->backup = (t_edge**)ft_memalloc(sizeof(t_edge*) * graph->node_num)))
		sys_error();
	backup_edges(graph);
}

int				get_line(char **line, t_type *type)
{
	int		tmp;
	int		is_node;

	*type = UNKNOWN;
	while ((tmp = get_next_line(STDIN_FILENO, line)) > 0 && **line == '#')
	{
		if (ft_strnequ(*line, "##", 2))
		{
			if (ft_strequ(*line, "##start"))
				*type = START;
			else if (ft_strequ(*line, "##end"))
				*type = FINISH;
			else
				*type = UNKNOWN;
		}
		ft_printf("%s\n", *line);
		free(*line);
	}
	if (tmp <= 0)
		return (tmp);
	if (!(is_node = (ft_strchr(*line, ' ') != NULL)) &&
	(*type == START || *type == FINISH))
		error();
	ft_printf("%s\n", *line);
	return (is_node ? NODE : EDGE);
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
