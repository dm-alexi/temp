/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belford.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:30:09 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/08 16:48:38 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lemin.h"

static void		reset_distance(t_graph *graph)
{
	int		i;

	i = 0;
	while (i < graph->node_num)
		graph->nodes[i++]->distance = INT_MAX;
	graph->start->distance = 0;
}

void			belford(t_graph *graph)
{
	reset_distance(graph);
}
