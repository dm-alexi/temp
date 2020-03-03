/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disjoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:30:24 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/10 20:11:02 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			remove_edge(t_node *node, t_edge **edge)
{
	t_edge	*t;
	t_edge	*tmp;

	if ((t = (*edge))->node == node)
	{
		*edge = (*edge)->next;
		free(t);
	}
	else
	{
		while (t->next->node != node)
			t = t->next;
		tmp = t->next;
		t->next = t->next->next;
		free(tmp);
	}
}

static void		reverse_path(t_edge *path)
{
	while (path->next)
	{
		find(path->node, path->next->node->edges)->len = -1;
		remove_edge(path->next->node, &(path->node->edges));
		path = path->next;
	}
}

void			reverse_paths(t_graph *graph)
{
	int		i;

	i = 0;
	while (i < graph->path_num)
		reverse_path(graph->paths[i++]);
}

static void		restore_path(t_edge *path)
{
	t_edge	*t;

	while (path->next)
	{
		if (!(t = (t_edge*)ft_memalloc(sizeof(t_edge))))
			sys_error();
		t->next = path->node->edges;
		t->node = path->next->node;
		t->len = 1;
		path->node->edges = t;
		find(path->node, path->next->node->edges)->len = 1;
		path = path->next;
	}
}

void			restore_paths(t_graph *graph)
{
	int		i;

	i = 0;
	while (i < graph->path_num)
		restore_path(graph->paths[i++]);
}
