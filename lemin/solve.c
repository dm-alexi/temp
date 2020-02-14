/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:22:05 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/14 19:30:45 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_edge	**clone(t_edge **paths, int n)
{
	int		i;
	t_edge	**arr;
	t_edge	*t;
	t_edge	*s;

	arr = (t_edge**)malloc(sizeof(t_edge*) * (n + 1));
	i = -1;
	while (++i < n)
	{
		s = paths[i];
		t = (t_edge*)malloc(sizeof(t_edge));
		arr[i] = t;
		t->len = 1;
		t->node = s->node;
		while (s->next)
		{
			t->next = (t_edge*)malloc(sizeof(t_edge));
			t->next->len = 1;
			t->next->node = s->next->node;
			t = t->next;
			s = s->next;
		}
		t->next = NULL;
	}
	return (arr);
}

static void		resolve(t_edge *s1, t_edge *f1, t_edge *s2, t_edge *f2)
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

static void		resolve_conflict(t_edge *p, t_edge *s2, t_edge *f2)
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

static void		resolve_conflicts(t_edge **paths, int n)
{
	t_edge	*s;
	t_edge	*f;
	int		rank;

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
	set_ranks(paths, n - 1);
	resolve_conflicts(paths, n);
}

void			solve(t_graph *graph)
{
	t_edge	**new_paths;
	int		c;

	bfs(graph);
	new_paths = NULL;
	while (graph->path_num < graph->path_max)
	{
		set_ranks(graph->paths, graph->path_num);
		new_paths = clone(graph->paths, graph->path_num);
		reverse_paths(graph);
		belford(graph);
		restore_paths(graph);
		if (!(new_paths[graph->path_num] = get_path(graph)))
			break ;
		resolve_conflicts(new_paths, graph->path_num + 1);
		if ((c = count_moves(new_paths, graph->path_num + 1, graph->ant_num)
		>= graph->moves))
			break ;
		delete_paths(graph->paths, graph->path_num);
		graph->paths = new_paths;
		++graph->path_num;
		graph->moves = c;
		new_paths = NULL;
	}
	delete_paths(new_paths, graph->path_num + 1);
}
