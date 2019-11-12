/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:31:18 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/12 21:36:37 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		i_swap(t_stack *t, char c)
{
	if (c != 'a' && c != 'b' && c != 's')
		error();
	if (c == 'a' || c == 's')
		swap(t->a);
	if (c == 'b' || c == 's')
		swap(t->b);
}

static void		i_push(t_stack *t, char c)
{
	if (c == 'a')
	{
		add(&(t->a), pop(&(t->b)));
		++t->a_count;
		--t->b_count;
	}
	else if (c == 'b')
	{
		add(&(t->b), pop(&(t->a)));
		++t->b_count;
		--t->a_count;
	}
	else
		error();
}

static void		i_rot(t_stack *t, char c, int rev)
{
	if (c != 'a' && c != 'b' && c != 'r')
		error();
	if (c == 'a' || c == 'r')
		t->a = rev ? t->a->u : t->a->d;
	if (c == 'b' || c == 'r')
		t->b = rev ? t->b->u : t->b->d;
}

void			exec(t_stack *t, char *s)
{
	int		len;

	len = ft_strlen(s);
	if (len == 2 && s[0] == 's')
		i_swap(t, s[1]);
	else if (len == 2 && s[0] == 'p')
		i_push(t, s[1]);
	else if (len == 2 && s[0] == 'r')
		i_rot(t, s[1], 0);
	else if (len == 3 && s[0] == 'r' && s[1] == 'r')
		i_rot(t, s[2], 1);
	if (!t->fin)
	{
		if (!(t->fin = ft_lstnew(s, len + 1)))
			mem_error();
		t->start = t->fin;
	}
	else
	{
		if (!(t->fin->next = ft_lstnew(s, len + 1)))
			mem_error();
		t->fin = t->fin->next;
	}
}

int				get_com(int fd, t_stack *t)
{
	int		r;
	int		len;
	char	*s;

	if ((r = get_next_line(fd, &s)) < 0)
		a_error("Input error.\n");
	if (!r)
		return (0);
	len = ft_strlen(s);
	if (len == 2 && s[0] == 's')
		i_swap(t, s[1]);
	else if (len == 2 && s[0] == 'p')
		i_push(t, s[1]);
	else if (len == 2 && s[0] == 'r')
		i_rot(t, s[1], 0);
	else if (len == 3 && s[0] == 'r' && s[1] == 'r')
		i_rot(t, s[2], 1);
	else
		error();
	free(s);
	return (1);
}

