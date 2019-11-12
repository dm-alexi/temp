/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:51:49 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/12 21:51:58 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		sorted(t_node *a)
{
	t_node	*t;

	if (a)
	{
		t = a->d;
		while (t != a)
		{
			if (t->num < t->u->num)
				return (0);
			t = t->d;
		}
	}
	return (1);
}

int		rsorted(t_node *a, int rev)
{
	t_node	*t;
	int		count;

	if (a->d == a || a->d->d == a)
		return (1);
	count = 0;
	if (a && (t = a->d))
		while (t != a)
		{
			if (rev ^ (t->num < t->u->num))
				if (++count > 1)
					return (0);
			t = t->d;
		}
	if (!count || (rev ^ (a->num > a->u->num)))
		return (1);
	return (0);
}
