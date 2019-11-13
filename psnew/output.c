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

#include <unistd.h>
#include "pushswap.h"

void	show_stacks(t_stack *t)
{
	t_node	*tmp;

	if (t->a)
	{
		ft_printf("%d\n", t->a->num);
		tmp = t->a->d;
		while (tmp != t->a && ft_printf("%d\n", tmp->num))
			tmp = tmp->d;
	}
	else
		ft_printf("Stack A empty\n");
	ft_printf("-----\n");
	if (t->b)
	{
		ft_printf("%d\n", t->b->num);
		tmp = t->a->d;
		while (tmp != t->b && ft_printf("%d\n", tmp->num))
			tmp = tmp->d;
	}
	else
		ft_printf("Stack B empty\n");
	ft_printf("--------\n");
}

void	print_log(t_stack *t)
{
	static const char	*arr[11] =
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	t_com				*lst;
	int					n;

	n = 0;
	lst = t->start;
	if (!lst)
		ft_printf("No list!");
	while (lst && ++n)
	{
		ft_printf("%s ", arr[lst->com]);
		lst = lst->next;
	}
	ft_printf("\nSorted in %d instructions.\n", n);
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
