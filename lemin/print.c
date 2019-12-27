/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:16 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/27 22:37:49 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_graph(t_graph *graph)
{
	int		i;

	ft_printf("--------------------\n");
	ft_printf("Number of ants: %d\nNodes:\n", graph->ant_num);
	i = -1;
	while (++i < graph->node_num)
		ft_printf("%s\t\t%d %d\n", graph->nodes[i]->name,
			graph->nodes[i]->x, graph->nodes[i]->y);
	ft_printf("--------------------\n");
}


void print_node(const t_node *a)
{
	ft_printf("Name: %s, x = %d, y = %d\n", a->name, a->x, a->y);
}
