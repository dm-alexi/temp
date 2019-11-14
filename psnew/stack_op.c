/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:31:18 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/13 23:53:14 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		exec_silent(t_stack *t, enum e_command com)
{
	if (com == SA || com == SS)
		swap(t->a);
	if (com == SB || com == SS)
		swap(t->b);
	if ((com == RA || com == RR) && t->a)
		t->a = t->a->d;
	if ((com == RB || com == RR) && t->b)
		t->b = t->b->d;
	if ((com == RRA || com == RRR) && t->a)
		t->a = t->a->u;
	if ((com == RRB || com == RRR) && t->b)
		t->b = t->b->u;
	if (com == PA)
	{
		add(&(t->a), pop(&(t->b)));
		++t->a_count;
		--t->b_count;
	}
	if (com == PB)
	{
		add(&(t->b), pop(&(t->a)));
		++t->b_count;
		--t->a_count;
	}
}

void			exec(t_stack *t, enum e_command com)
{
	exec_silent(t, com);
	if (!t->fin)
	{
		if (!(t->fin = (t_com*)malloc(sizeof(t_com))))
			mem_error();
		t->fin->com = com;
		t->fin->next = NULL;
		t->start = t->fin;
	}
	else
	{
		if (!(t->fin->next = (t_com*)malloc(sizeof(t_com))))
			mem_error();
		t->fin->next->com = com;
		t->fin->next->next = NULL;
		t->fin = t->fin->next;
	}
}

static void		reset_com(t_stack *t, enum e_command *com)
{
	if (t->a_count < 2)
	{
		if (*com == SA || *com == RA || *com == RRA ||
		(*com == PB && !t->a_count))
			*com = NO_COM;
		else if (*com == RR)
			*com = RB;
		else if (*com == RRR)
			*com = RRB;
		else if (*com == SS)
			*com = SB;
	}
	if (t->b_count < 2)
	{
		if (*com == SB || *com == RB || *com == RRB ||
		(*com == PA && !t->b_count))
			*com = NO_COM;
		else if (*com == RR)
			*com = RA;
		else if (*com == RRR)
			*com = RRA;
		else if (*com == SS)
			*com = SA;
	}
}

int				get_com(int fd, t_stack *t, t_flags *flags)
{
	static const char	*arr[11] =
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	enum e_command		com;
	int					r;
	char				*s;

	if ((r = get_next_line(fd, &s)) < 0)
		a_error("Input error.\n");
	if (!r)
		return (0);
	com = SA - 1;
	while (++com <= RRR)
		if (ft_strequ(s, arr[com]))
			break ;
	if (com > RRR)
		error();
	if (flags->verbose)
		ft_printf(flags->colored ? (RED "%s\n" WHITE) : "%s\n", arr[com]);
	reset_com(t, &com);
	exec_silent(t, com);
	if (flags->verbose)
		show_stacks(t, flags, com);
	free(s);
	return (1);
}
