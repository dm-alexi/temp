/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:16 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/29 17:40:08 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_node(const t_node *a)
{
	t_edge	*tmp;

	ft_printf("%-12s: (x, y) = (%d, %d)\tdistance: %d\tconnected to: ",
		a->name, a->x, a->y, a->distance);
	tmp = a->edges;
	while (tmp)
	{
		ft_printf("%s (%d); ", tmp->node->name, tmp->len);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	print_graph(t_graph *graph)
{
	int		i;

	ft_printf("--------------------\n");
	ft_printf("Number of ants: %d\nNodes:\n", graph->ant_num);
	ft_printf("Starting node: %s\n", graph->start->name);
	ft_printf("Ending node:   %s\n", graph->finish->name);
	i = 0;
	while (i < graph->node_num)
		print_node(graph->nodes[i++]);
	ft_printf("--------------------\n");
}

void	print_path(t_edge *path)
{
	ft_printf("Path:\n");
	while (path)
	{
		ft_printf("%s ", path->node->name);
		path = path->next;
	}
	ft_printf("\n");
}
