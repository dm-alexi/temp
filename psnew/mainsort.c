/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:12:36 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/14 19:54:01 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		adjust_ab(t_stack *t, int n)
{
	int		i;
	int		j;
	int		m1;
	int		m2;
	t_node	*tmp;

	i = 0;
	j = 0;
	tmp = t->a;
	while (tmp->num != n && ++i)
		tmp = tmp->d;
	if (t->b_count > 1 && (tmp = t->b))
		while (!(tmp->num < n && tmp->u->num > n) &&
		!(tmp->num > tmp->u->num && (n < tmp->u->num || n > tmp->num)) && ++j)
			tmp = tmp->d;
	m1 = i > j ? i : j;
	m2 = t->a_count - i > t->b_count - j ? t->a_count - i : t->b_count - j;
	if (m1 <= m2 && m1 <= i + t->b_count - j && m1 <= j + t->a_count - i)
		roll(t, i, j);
	else if (m2 <= m1 && m2 <= i + t->b_count - j && m2 <= j + t->a_count - i)
		roll(t, -(t->a_count - i), -(t->b_count - j));
	else if (i + t->b_count - j <= j + t->a_count - i)
		roll(t, i, -(t->b_count - j));
	else
		roll(t, -(t->a_count - i), j);
}

static void		adjust_ba(t_stack *t, int n)
{
	int		i;
	int		j;
	int		m1;
	int		m2;
	t_node	*tmp;

	i = 0;
	j = 0;
	tmp = t->b;
	while (tmp->num != n && ++j)
		tmp = tmp->d;
	if (t->a_count > 1 && (tmp = t->a))
		while (!(tmp->num > n && tmp->u->num < n) &&
		!(tmp->num < tmp->u->num && (n > tmp->u->num || n < tmp->num)) && ++i)
			tmp = tmp->d;
	m1 = i > j ? i : j;
	m2 = t->a_count - i > t->b_count - j ? t->a_count - i : t->b_count - j;
	if (m1 <= m2 && m1 <= i + t->b_count - j && m1 <= j + t->a_count - i)
		roll(t, i, j);
	else if (m2 <= m1 && m2 <= i + t->b_count - j && m2 <= j + t->a_count - i)
		roll(t, -(t->a_count - i), -(t->b_count - j));
	else if (i + t->b_count - j <= j + t->a_count - i)
		roll(t, i, -(t->b_count - j));
	else
		roll(t, -(t->a_count - i), j);
}

void			mainsort(t_stack *t)
{
	while (!rsorted(t->a, 0) && t->a_count > 3)
	{
		adjust_ab(t, find_closest(t, 0));
		exec(t, PB);
	}
	if (!rsorted(t->a, 0))
		exec(t, SA);
	while (t->b_count)
	{
		adjust_ba(t, find_closest(t, 1));
		exec(t, PA);
	}
	if (!sorted(t->a))
		rsort(t);
}
