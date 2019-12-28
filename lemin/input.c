/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:25:49 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/28 15:51:54 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lemin.h"
#define NODE 1
#define EDGE 2

static int		read_int(void)
{
	char	*line;
	int		tmp;
	int		n;

	while ((tmp = get_next_line(STDIN_FILENO, &line)) > 0 && *line == '#')
		free(line);
	if (tmp <= 0)
		tmp ? sys_error() : error();
	if (((n = ft_atoi(line))) <= 0)
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

t_node 			*node_bsearch(const char *key, t_node **base, size_t num)
{
	int				k;
	t_node	**l;
	t_node	**r;
	t_node	**m;

	if (!key || !base || !num)
		return (NULL);
	l = base;
	r = l + num - 1;
	while (l <= r)
	{
		m = l + (r - l) / 2;
		if ((k = ft_strcmp(key, (*m)->name)) < 0)
			r = m - 1;
		else if (k > 0)
			l = m + 1;
		else
			return (*m);
	}
	return (NULL);
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
	char	*s;
	t_node	*a;
	t_node	*b;

	if (!(s = ft_strchr(*line, '-')) || ft_strchr(s + 1, '-'))
		error();
	if (!(b = node_bsearch(s + 1, graph->nodes, graph->node_num)))
		error();
	*s = '\0';
	if (!(a = node_bsearch(*line, graph->nodes, graph->node_num)))
		error();
	ft_lstadd(&(a->nodes), ft_lstnew(&b, sizeof(t_node**)));
	ft_lstadd(&(b->nodes), ft_lstnew(&a, sizeof(t_node**)));
	free(*line);
}
/*
static void		get_edges(t_graph *graph, char **line)
{
	char	*s;
	t_node	*tmp;

	if (!(s = ft_strchr(*line, '-')));
	if (s && (tmp = node_bsearch(s + 1, graph->nodes, graph->node_num)))
		print_node(tmp);
	*s = '\0';
	if ((tmp = node_bsearch(*line, graph->nodes, graph->node_num)))
		print_node(tmp);
	free(*line);
}
*/
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
