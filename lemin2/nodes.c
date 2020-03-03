/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:12 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/03 13:15:07 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lemin.h"

static int		get_coordinate(char *s)
{
	long	n;
	char	*t;

	t = s;
	if (*t == '-')
		++t;
	if (!*t)
		error();
	while (*t)
		if (!ft_isdigit(*t++))
			error();
	if ((n = ft_strtol(s, NULL, 10)) > INT_MAX || n < INT_MIN)
		error();
	return ((int)n);
}

static t_list	*new_node(char *line, t_type type)
{
	char	*s;
	t_node	node;

	if (*line == 'L')
		error();
	if (!(s = ft_strrchr(line, ' ')))
		error();
	node.y = get_coordinate(s + 1);
	*s = '\0';
	if (!(s = ft_strrchr(line, ' ')))
		error();
	node.x = get_coordinate(s + 1);
	*s = '\0';
	if (!*line)
		error();
	node.name = ft_strdup(line);
	node.edges = NULL;
	node.prev = NULL;
	node.distance = (type == START ? 0 : -1);
	node.type = type;
	node.rank = 0;
	free(line);
	return (ft_lstnew(&node, sizeof(t_node)));
}

static int		compare(const void *a, const void *b)
{
	int		res;

	if (!(res = ft_strcmp((*((t_node **)a))->name, (*((t_node **)b))->name))
	&& a != b)
		error();
	return (res);
}

void			get_nodes(t_graph *graph, char **line)
{
	t_list	*lst;
	t_list	*tmp;
	t_type	type;
	int		i;

	lst = NULL;
	while ((i = get_line(line, &type)) == NODE && ++graph->node_num)
		ft_lstadd(&lst, new_node(*line, type));
	if (i <= 0)
		i ? sys_error() : error();
	if (!(graph->nodes = (t_node **)malloc(sizeof(t_node *) *
	graph->node_num * 2)))
		sys_error();
	i = 0;
	while (lst)
	{
		tmp = lst->next;
		graph->nodes[i++] = lst->content;
		free(lst);
		lst = tmp;
	}
	ft_qsort(graph->nodes, graph->node_num, sizeof(t_node *), compare);
}
