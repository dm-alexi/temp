/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:38:52 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/08 19:51:22 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void path_restore(t_graph *graph, t_edge *path)
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
