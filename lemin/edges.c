/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:08:30 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/29 17:41:34 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_node	*node_bsearch(const char *key, t_node **base, size_t num)
{
	int		k;
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

static void		add_edge(t_edge **edge, t_node *node)
{
	t_edge	*tmp;
	t_edge	*t;

	tmp = *edge;
	if (*edge == NULL || ft_strcmp(node->name, (*edge)->node->name) < 0)
	{
		if (!(*edge = (t_edge*)malloc(sizeof(t_edge))))
			sys_error();
		(*edge)->node = node;
		(*edge)->len = 1;
		(*edge)->next = tmp;
		return ;
	}
	while (tmp->next && ft_strcmp(node->name, tmp->next->node->name) > 0)
		tmp = tmp->next;
	if (tmp->next && !ft_strcmp(node->name, tmp->next->node->name))
		return ;
	t = tmp->next;
	if (!(tmp->next = (t_edge*)malloc(sizeof(t_edge))))
		sys_error();
	tmp->next->node = node;
	tmp->next->len = 1;
	tmp->next->next = t;
}

static void		get_edge(t_graph *graph, char *line)
{
	char	*s;
	t_node	*a;
	t_node	*b;

	if (!(s = ft_strchr(line, '-')) || ft_strchr(s + 1, '-'))
		error();
	if (!(b = node_bsearch(s + 1, graph->nodes, graph->node_num)))
		error();
	*s = '\0';
	if (!(a = node_bsearch(line, graph->nodes, graph->node_num)))
		error();
	add_edge(&(a->nodes), b);
	add_edge(&(b->nodes), a);
	free(line);
}

void			get_edges(t_graph *graph, char **line)
{
	int			tmp;
	t_command	com;

	get_edge(graph, *line);
	while ((tmp = get_line(line, &com)) == EDGE)
		get_edge(graph, *line);
	if (tmp < 0)
		sys_error();
	if (tmp)
		error();
}
