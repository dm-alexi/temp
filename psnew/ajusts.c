/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ajusts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:09:34 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/12 21:10:21 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		adjust_count_ab(t_stack *t, int n)
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
	if (t->b_count <= 1)
		return (i <= t->a_count / 2 ? i : t->a_count - i);
	tmp = t->b;
	while (!(tmp->num < n && tmp->u->num > n) &&
	!(tmp->num > tmp->u->num && (n < tmp->u->num || n > tmp->num)) && ++j)
		tmp = tmp->d;
	m1 = i > j ? i : j;
	m2 = t->a_count - i > t->b_count - j ? t->a_count - i : t->b_count - j;
	m1 = m1 < i + t->b_count - j ? m1 : i + t->b_count - j;
	m2 = m2 < j + t->a_count - i ? m2 : j + t->a_count - i;
	return (m1 < m2 ? m1 : m2);
}

static int		adjust_count_ba(t_stack *t, int n)
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
	if (t->a_count <= 1)
		return (i <= t->b_count / 2 ? j : t->b_count - j);
	tmp = t->a;
	while (!(tmp->num > n && tmp->u->num < n) &&
	!(tmp->num < tmp->u->num && (n > tmp->u->num || n < tmp->num)) && ++i)
		tmp = tmp->d;
	m1 = i > j ? i : j;
	m2 = t->a_count - i > t->b_count - j ? t->a_count - i : t->b_count - j;
	m1 = m1 < i + t->b_count - j ? m1 : i + t->b_count - j;
	m2 = m2 < j + t->a_count - i ? m2 : j + t->a_count - i;
	return (m1 < m2 ? m1 : m2);
}

int             find_closest(t_stack *t, int rev)
{
    int		moves;
	int		num;
	int		tmp;
	t_node	*node;
    t_node  *start;

    start = rev ? t->b : t->a;
    num = start->num;
    moves = rev ? adjust_count_ba(t, num) : adjust_count_ab(t, num);
    node = start->d;
    while (node != start)
	{
		if ((tmp = (rev ? adjust_count_ba(t, node->num) :
        adjust_count_ab(t, node->num))) < moves)
		{
			moves = tmp;
			num = node->num;
		}
		node = node->d;
	}
    return (num);
}