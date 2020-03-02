/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:45:26 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/26 18:45:45 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	set_rank(t_edge *path, int rank)
{
	while ((path = path->next)->node->type != FINISH)
		path->node->rank = rank;
}

void	set_ranks(t_edge **paths, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		set_rank(paths[i], i + 1);
		++i;
	}
}

void	reset_ranks(t_graph *graph)
{
	int		i;

	i = -1;
	while (++i < graph->node_num)
		graph->nodes[i]->rank = 0;
}
