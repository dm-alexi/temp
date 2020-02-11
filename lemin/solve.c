/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:22:05 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/10 21:00:18 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	resolve(t_edge *s1, t_edge *f1, t_edge *s2, t_edge *f2)
{
    t_edge	*t;
    t_edge	*tmp;

    t = s1->next;
    s1->next = f2->next;
    while ((tmp = t) != f1)
	{
		t = t->next;
		free(tmp);
	}
	t = s2->next;
	s2->next = f1->next;
    while ((tmp = t) != f2)
	{
		t = t->next;
		free(tmp);
	}
    free(f1);
    free(f2);
}

void	resolve_conflict(t_edge *p, t_edge *s2, t_edge *f2)
{
	t_edge	*s1;
	t_edge	*f1;

	s1 = p;
	while (s1->node != f2->node)
		s1 = s1->next;
	f1 = s1->next;
	while (f1->node != s2->node)
		f1 = f1->next;
	resolve(s1, f1, s2, f2);
}

void	resolve_conflicts(t_edge **paths, int n)
{
    t_edge	*s;
    t_edge	*f;
    int		rank;
    int		i;

    s = paths[n - 1]->next;
    while ((rank = s->node->rank) == paths[n - 1]->node->rank)
		if (s->next->node->type == FINISH)
			return ;
		else
			s = s->next;
	f = s->next;
	while (f->next->node->rank == rank)
		f = f->next;
	resolve_conflict(paths[rank - 1], s, f);
	s = paths[n - 1];
	paths[n - 1] = paths[rank - 1];
	paths[rank - 1] = s;
	set_rank(paths[n - 1], 0);
	i = -1;
	while (++i < n - 1)
		set_rank(paths[i], i + 1);
	resolve_conflicts(paths, n);
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

void	solve(t_graph *graph)
{
	t_edge	**new_paths;
	int		i;
	int		c;

	while (graph->path_num < graph->path_max)
	{
		reset_distance(graph);
		set_ranks(graph);
		new_paths = clone(graph->paths, graph->path_num);
		i = 0;
		while (i < graph->path_num)
			path_reverse(graph->paths[i++]);
		belford(graph);
		new_paths[graph->path_num] = get_path(graph);
		while (--i >= 0)
			path_restore(graph->paths[i]);
		resolve_conflicts(new_paths, graph->path_num + 1);
		if ((c = count_moves(new_paths, graph->path_num + 1, graph->ant_num))
			>= graph->moves)
		{
			delete_paths(new_paths, graph->path_num + 1);
			print_graph(graph);
			return ;
		}
		delete_paths(graph->paths, graph->path_num);
		graph->paths = new_paths;
		++graph->path_num;
		graph->moves = c;
		print_graph(graph);
	}
}
