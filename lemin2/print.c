/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:16 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/10 20:05:41 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_node(const t_node *a)
{
	t_edge	*tmp;

	ft_printf("%-12s: (x, y) = (%d, %d)\trank = %d\tdist: %10d\tconnected to: ",
		a->name, a->x, a->y, a->rank, a->distance);
	tmp = a->edges;
	while (tmp)
	{
		ft_printf("%s (%d); ", tmp->node->name, tmp->len);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

static void	print_path(t_edge *path)
{
	while (path)
	{
		ft_printf("%s ", path->node->name);
		path = path->next;
	}
	ft_printf("\n");
}

static void	print_paths(t_edge **paths, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_printf("Path %3d: ", i + 1);
		print_path(paths[i++]);
	}
}

void		print_graph(t_graph *graph)
{
	int		i;

	ft_printf("--------------------\n");
	ft_printf("Number of ants: %d\n", graph->ant_num);
	ft_printf("Starting node: %s\n", graph->start->name);
	ft_printf("Ending node:   %s\n", graph->finish->name);
	i = 0;
	while (i < graph->node_num)
		print_node(graph->nodes[i++]);
	ft_printf("Maximum paths possible: %d\n", graph->path_max);
	ft_printf("--------------------\n");
	print_paths(graph->paths, graph->path_num);
	ft_printf("Moves: %d\n", graph->moves);
}
