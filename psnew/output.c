/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:45:55 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/14 00:01:14 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#define WHITE "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"

void	show_a(t_stack *t, t_flags *flags, enum e_command com)
{
	t_node	*tmp;

	if (((com == RA || com == RR) && t->a_count > 1) || com == PB)
		ft_printf(flags->colored ? (GREEN "_ " WHITE) : "_ ");
	if (t->a)
	{
		ft_printf(flags->colored && (com == PA || com == RRA || com == RRR ||
		com == SA || com == SS) ? (GREEN "%d " WHITE) : "%d ", t->a->num);
		if (((tmp = t->a->d) != t->a) && ft_printf(flags->colored && (com == SA
		|| com == SS) ? (GREEN "%d " WHITE) : "%d ", tmp->num))
			tmp = tmp->d;
		while (tmp != t->a && tmp != t->a->u && ft_printf("%d ", tmp->num))
			tmp = tmp->d;
		if (tmp != t->a)
			ft_printf(flags->colored && (com == RA || com == RR) &&
			t->a_count > 1 ? (GREEN "%d " WHITE) : "%d ", tmp->num);
		if (com == RRA || com == RRR)
			ft_printf(flags->colored ? (GREEN "_" WHITE) : "_");
	}
}

void	show_b(t_stack *t, t_flags *flags, enum e_command com)
{
	t_node	*tmp;

	if (((com == RB || com == RR) && t->b_count > 1) || com == PA)
		ft_printf(flags->colored ? (GREEN "_ " WHITE) : "_ ");
	if (t->b)
	{
		ft_printf(flags->colored && (com == PB || com == RRB || com == RRR ||
		com == SB || com == SS) ? (GREEN "%d " WHITE) : "%d ", t->b->num);
		if (((tmp = t->b->d) != t->b) && ft_printf(flags->colored && (com == SB
		|| com == SS) ? (GREEN "%d " WHITE) : "%d ", tmp->num))
			tmp = tmp->d;
		while (tmp != t->b && tmp != t->b->u && ft_printf("%d ", tmp->num))
			tmp = tmp->d;
		if (tmp != t->b)
			ft_printf(flags->colored && (com == RB || com == RR) ?
			(GREEN "%d " WHITE) : "%d ", tmp->num);
		if (com == RRB || com == RRR)
			ft_printf(flags->colored ? (GREEN "_" WHITE) : "_");
	}
}

void	show_stacks(t_stack *t, t_flags *flags, enum e_command com)
{
	static const char	*arr[11] =
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	if (com != NO_COM)
		ft_printf(flags->colored ? (RED "%s\n" WHITE) : "%s\n", arr[com]);
	ft_printf("A: ");
	show_a(t, flags, com);
	ft_printf("\nB: ");
	show_b(t, flags, com);
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
