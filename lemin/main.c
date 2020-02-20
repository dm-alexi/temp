/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:08 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/20 23:01:57 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	t_graph		*graph;

	graph = get_graph();
	solve(graph);
	distribute(graph);
	if (ac == 2 && ft_strequ(av[1], "-v"))
		ft_printf("\nMoves: %d", graph->moves);
	//print_graph(graph);
	delete_graph(graph);
	return (0);
}
