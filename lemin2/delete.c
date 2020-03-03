/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:21:34 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/03 15:04:46 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			delete_graph(t_graph *graph)
{
	int		i;

	i = 0;
	//delete_paths(graph->backup, graph->node_num);
	delete_paths(graph->paths, graph->path_num);
	while (i < graph->node_num)
	{
		free(graph->nodes[i]->name);
		delete_path(graph->nodes[i]->edges);
		free(graph->nodes[i]);
		++i;
	}
	free(graph->nodes);
	free(graph->backup);
	free(graph->path_len);
	free(graph->ants);
	free(graph);
}

void			delete_path(t_edge *path)
{
	t_edge	*t;

	while ((t = path))
	{
		path = path->next;
		ft_memdel((void**)&t);
	}
}

void			delete_paths(t_edge **paths, int n)
{
	if (paths)
	{
		while (--n >= 0)
			delete_path(paths[n]);
		free(paths);
	}
}
