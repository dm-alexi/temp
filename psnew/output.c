/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:45:55 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/13 23:05:27 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#define WHITE "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"

void	show_a(t_stack *t, t_flags *flags, enum e_command com)
{
	t_node	*tmp;
	
	if (com == RA || com == RR || com == PB)
		ft_printf(flags->colored ? (GREEN "_ " WHITE) : "_ ");
	ft_printf(flags->colored && (com == PA || com == RRA || com == RR) ?
	(GREEN "%d " WHITE) : "%d ", t->a->num);
	tmp = t->a->d;
	while (tmp != t->a->u && ft_printf("%d ", tmp->num))
		tmp = tmp->d;
	if (tmp != t->a)
		ft_printf(flags->colored && (com == RA || com == RR) ?
		(GREEN "%d " WHITE) : "%d ", t->a->num);
	if (com == RRA || com == RRR)
		ft_printf(flags->colored ? (GREEN "_ " WHITE) : "_ ");
}

void	show_stacks(t_stack *t, t_flags *flags, enum e_command com)
{
	static const char	*arr[11] =
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	t_node	*tmp;

	if (com >= 0)
		ft_printf(flags->colored ? (RED "%s\n" WHITE) : "%s\n", arr[com]);
	ft_printf("A: ");
	if (t->a)
		show_a(t, flags, com);
	/*{
		ft_printf(GREEN "%d " WHITE, t->a->num);
		tmp = t->a->d;
		while (tmp != t->a && ft_printf("%d ", tmp->num))
			tmp = tmp->d;
	}*/
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
