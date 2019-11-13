/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:45:55 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/12 22:10:00 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	show_stacks(t_stack *t, t_flags *flags, char *lastcom)
{
	t_node	*tmp;

	if (lastcom && flags->filename)
		ft_printf("%s\n", lastcom);
	ft_printf("A: ");
	if (t->a)
	{
		ft_printf("%d ", t->a->num);
		tmp = t->a->d;
		while (tmp != t->a && ft_printf("%d ", tmp->num))
			tmp = tmp->d;
	}
	ft_printf("\nB: ");
	if (t->b)
	{
		ft_printf("%d ", t->b->num);
		tmp = t->b->d;
		while (tmp != t->b && ft_printf("%d ", tmp->num))
			tmp = tmp->d;
	}
	ft_printf("\n\n");
}

void	print_result(t_stack *t, int fd)
{
	static const char	*arr[11] =
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	t_com				*tmp;

	while (t->start)
	{
		tmp = t->start->next;
		ft_dprintf(fd, "%s\n", arr[t->start->com]);
		free(t->start);
		t->start = tmp;
	}
}
