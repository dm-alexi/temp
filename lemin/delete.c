/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:21:34 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/29 17:39:45 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	delete_graph(t_graph *graph)
{
	int		i;
	t_edge	*tmp;

	i = 0;
	while (i < graph->node_num)
	{
		free(graph->nodes[i]->name);
		while (graph->nodes[i]->nodes)
		{
			tmp = graph->nodes[i]->nodes->next;
			free(graph->nodes[i]->nodes);
			graph->nodes[i]->nodes = tmp;
		}
		free(graph->nodes[i]);
		++i;
	}
	free(graph->nodes);
	free(graph);
}
