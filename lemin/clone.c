/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:03:16 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/10 20:03:27 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_edge	**clone(t_edge **paths, int n)
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
