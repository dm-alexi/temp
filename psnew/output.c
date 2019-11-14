/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:45:55 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/14 21:45:22 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#define ARROW_LEFT "\xE2\x86\x90 "
#define ARROW_UP "\xE2\x86\x91 "
#define ARROW_RIGHT "\xE2\x86\x92 "
#define ARROW_DOWN "\xE2\x86\x93 "
#define ARROWS_LR "\xE2\x86\x94 "
#define GREEN_ARROW_LEFT "\x1B[32m\xE2\x86\x90 \x1B[0m"
#define GREEN_ARROW_UP "\x1B[32m\xE2\x86\x91 \x1B[0m"
#define GREEN_ARROW_RIGHT "\x1B[32m\xE2\x86\x92 \x1B[0m"
#define GREEN_ARROW_DOWN "\x1B[32m\xE2\x86\x93 \x1B[0m"
#define GREEN_ARROWS_LR "\x1B[32m\xE2\x86\x94 \x1B[0m"

void	show_a(t_stack *t, t_flags *flags, enum e_command com)
{
	t_node	*tmp;

	if (com == RA || com == RR)
		ft_printf(flags->colored ? GREEN_ARROW_LEFT : ARROW_LEFT);
	if (com == PB)
		ft_printf(flags->colored ? GREEN_ARROW_DOWN : ARROW_DOWN);
	if (t->a)
	{
		ft_printf(flags->colored && (com == PA || com == RRA || com == RRR ||
		com == SA || com == SS) ? (GREEN "%d " WHITE) : "%d ", t->a->num);
		if (com == SA || com == SS)
			ft_printf(flags->colored ? GREEN_ARROWS_LR : ARROWS_LR);
		if (((tmp = t->a->d) != t->a) && ft_printf(flags->colored && (com == SA
		|| com == SS || ((com == RA || com == RR) && t->a_count == 2)) ?
		(GREEN "%d " WHITE) : "%d ", tmp->num))
			tmp = tmp->d;
		while (tmp != t->a && tmp != t->a->u && ft_printf("%d ", tmp->num))
			tmp = tmp->d;
		if (tmp != t->a)
			ft_printf(flags->colored && (com == RA || com == RR) ?
			(GREEN "%d " WHITE) : "%d ", tmp->num);
		if (com == RRA || com == RRR)
			ft_printf(flags->colored ? GREEN_ARROW_RIGHT : ARROW_RIGHT);
	}
}

void	show_b(t_stack *t, t_flags *flags, enum e_command com)
{
	t_node	*tmp;

	if (com == RB || com == RR)
		ft_printf(flags->colored ? GREEN_ARROW_LEFT : ARROW_LEFT);
	if (com == PA)
		ft_printf(flags->colored ? GREEN_ARROW_UP : ARROW_UP);
	if (t->b)
	{
		ft_printf(flags->colored && (com == PB || com == RRB || com == RRR ||
		com == SB || com == SS) ? (GREEN "%d " WHITE) : "%d ", t->b->num);
		if (com == SB || com == SS)
			ft_printf(flags->colored ? GREEN_ARROWS_LR : ARROWS_LR);
		if (((tmp = t->b->d) != t->b) && ft_printf(flags->colored && (com == SB
		|| com == SS || ((com == RB || com == RR) && t->b_count == 2)) ?
		(GREEN "%d " WHITE) : "%d ", tmp->num))
			tmp = tmp->d;
		while (tmp != t->b && tmp != t->b->u && ft_printf("%d ", tmp->num))
			tmp = tmp->d;
		if (tmp != t->b)
			ft_printf(flags->colored && (com == RB || com == RR) ?
			(GREEN "%d " WHITE) : "%d ", tmp->num);
		if (com == RRB || com == RRR)
			ft_printf(flags->colored ? GREEN_ARROW_RIGHT : ARROW_RIGHT);
	}
}

void	show_stacks(t_stack *t, t_flags *flags, enum e_command com)
{
	if (com == FINAL)
		ft_printf(flags->colored ? (RED "FINAL\n" WHITE) : "FINAL\n");
	ft_printf(flags->colored ? (YELLOW "A: " WHITE) : "A: ");
	if (flags->colored && com == FINAL)
		ft_printf(GREEN);
	show_a(t, flags, com);
	ft_printf(flags->colored ? (YELLOW "\nB: " WHITE) : "\nB: ");
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
