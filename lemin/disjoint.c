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

t_edge			*find(t_node *node, t_edge *edge)
{
	while (edge->node && edge->node != node)
		edge = edge->next;
	return (edge);
}

static void		remove_edge(t_node *node, t_edge **edge)
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

void			path_reverse(t_edge *path)
{
	while (path->next)
	{
		find(path->node, path->next->node->edges)->len = -1;
		remove_edge(path->next->node, &(path->node->edges));
		path = path->next;
	}
}
