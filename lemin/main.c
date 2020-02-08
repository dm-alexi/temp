/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:08 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/08 16:55:10 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_graph		*graph;
	t_edge		*path;

	graph = get_graph();
	//print_graph(graph);
	bfs(graph);
	print_graph(graph);
	print_path(path = get_path(graph));
	path_split(graph, path);
	print_graph(graph);
	print_path(path);
	delete_path(path);
	delete_graph(graph);
	return (0);
}
