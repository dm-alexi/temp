/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:30:28 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/29 16:38:55 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		setup(t_graph *graph)
{
	int		i;
	int		s;
	t_edge	*t;

	if (!(graph->path_len = (int*)ft_memalloc(sizeof(int) * graph->path_num)) ||
	!(graph->ants = (int*)malloc(sizeof(int) * graph->path_num)))
		sys_error();
	i = -1;
	s = 0;
	while (++i < graph->path_num)
	{
		t = graph->paths[i];
		while (t->node->type != FINISH)
		{
			t->len = 0;
			t = t->next;
			++graph->path_len[i];
		}
		s += graph->path_len[i];
	}
	i = -1;
	while (++i < graph->path_num)
		graph->ants[i] = graph->moves - graph->path_len[i] +
		(i >= graph->path_num - (graph->ant_num + s) % graph->path_num);
}

static int		send_ants(t_graph *graph, int sent)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < graph->path_num)
		if (graph->ants[i] && sent + j < graph->ant_num &&
		graph->ants[i]-- && ++j)
			graph->paths[i]->len = sent + j;
		else
			graph->paths[i]->len = 0;
	return (sent + j);
}

static void		promote_ants(t_graph *graph)
{
	t_edge	*t;
	int		prev;
	int		i;

	i = 0;
	while (i < graph->path_num)
	{
		t = graph->paths[i++];
		while (t->len == 0 && t->node->type != FINISH)
			t = t->next;
		prev = 0;
		while (t->len && t->node->type != FINISH)
		{
			ft_printf("L%d-%s ", t->len, t->next->node->name);
			ft_memswap(&prev, &t->len, sizeof(int));
			t = t->next;
		}
		if (t->node->type != FINISH)
			t->len = prev;
	}
}

void			distribute(t_graph *graph)
{
	int		sent;
	int		i;

	setup(graph);
	sent = send_ants(graph, 0);
	i = -1;
	while (++i < graph->moves)
	{
		promote_ants(graph);
		ft_printf("\n");
		if (sent < graph->ant_num)
			sent = send_ants(graph, sent);
	}
}
