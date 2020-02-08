/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belford.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:30:09 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/08 17:23:14 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lemin.h"

void		reset_distance(t_graph *graph)
{
	int		i;

	i = 0;
	while (i < graph->node_num)
		graph->nodes[i++]->distance = -1;
	graph->start->distance = 0;
}
/*
void			belford(t_graph *graph)
{
	int		i;
	int		j;
	int		fin;
	t_edge	*t;
	
	reset_distance(graph);
	i = 0;
	while (i < graph->node_num - 1)
	{
		j = -1;
		fin = 1;
		while (++j < graph->node_num && (t = graph->nodes[j]->edges))
			while (t)
			{
				if ()
			}

	}
}*/
