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
	t_list	*lst;
	int		n;

	n = 0;
	lst = t->start;
	if (!lst)
		ft_printf("No list!");
	while (lst && ++n)
	{
		ft_printf("%s ", lst->content);
		lst = lst->next;
	}
	ft_printf("\nCom len = %d\n", n);
}

void	print_result(t_stack *t, int fd)
{
	t_list	*tmp;

	while (t->start)
	{
		tmp = t->start->next;
		write(fd, t->start->content, t->start->content_size - 1);
		write(fd, "\n", 1);
		free(t->start->content);
		free(t->start);
		t->start = tmp;
	}
}
