/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:47:42 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/12 21:48:49 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	roll(t_stack *t, int a, int b)
{
	if (a > 0 && b > 0)
		while (a && b && a-- && b--)
			exec(t, RR);
	else if (a < 0 && b < 0)
		while (a && b && a++ && b++)
			exec(t, RRR);
	if (a > 0)
		while (a--)
			exec(t, RA);
	else
		while (a++)
			exec(t, RRA);
	if (b > 0)
		while (b--)
			exec(t, RB);
	else
		while (b++)
			exec(t, RRB);
}

void	rsort(t_stack *t)
{
	t_node	*tmp;
	int		i;

	tmp = t->a->d;
	i = 0;
	while (++i && tmp->num > tmp->u->num)
		tmp = tmp->d;
	if (i > t->a_count / 2)
		i = -(t->a_count - i);
	roll(t, i, 0);
}

void	sort_3(t_stack *t)
{
	if (sorted(t->a))
		return ;
	else if (rsorted(t->a, 0))
		rsort(t);
	else if (t->a->num < t->a->d->num && t->a->num < t->a->d->d->num)
	{
		exec(t, SA);
		exec(t, RA);
	}
	else if (t->a->num > t->a->d->num && t->a->num > t->a->d->d->num)
	{
		exec(t, SA);
		exec(t, RRA);
	}
	else
		exec(t, SA);
}

void	sort(t_stack *t)
{
	if (sorted(t->a))
		return ;
	else if (rsorted(t->a, 0))
		rsort(t);
	else if (t->a_count == 3)
		sort_3(t);
	else
		mainsort(t);
}
