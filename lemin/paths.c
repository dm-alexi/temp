/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:30:43 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/12 19:30:44 by sscarecr         ###   ########.fr       */
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

t_edge	*get_path(t_graph *graph)
{
	t_edge	*res;
	t_edge	*tmp;
	int		i;

	if ((i = graph->finish->distance) <= 0)
		return (NULL);
	if (!(res = (t_edge*)ft_memalloc(sizeof(t_edge))))
		sys_error();
	res->node = graph->finish;
	while (res->node->prev)
	{
		if (!(tmp = (t_edge*)malloc(sizeof(t_edge))))
			sys_error();
		tmp->node = res->node->prev;
		tmp->next = res;
		res = tmp;
	}
	return (res);
}

int		path_len(t_edge *path)
{
	int		n;

	n = 0;
	while ((path = path->next))
		++n;
	return (n);
}

int		count_moves(t_edge **paths, int n_paths, int ants)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (i < n_paths)
		n += path_len(paths[i++]);
	return ((ants - n_paths + n) / n_paths + ((ants + n) % n_paths > 0));
}
