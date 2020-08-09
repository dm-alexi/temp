/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:36:53 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 21:51:48 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Insert element in a sorted linked list
*/

void	ft_lstadd_sorted(t_list **alst, t_list *newlst,
	int (*compar)(const void*, const void*))
{
	t_list	*t;

	if (!alst || !newlst || !compar)
		return ;
	if (!*alst || compar((*alst)->content, newlst->content) > 0)
	{
		newlst->next = *alst;
		*alst = newlst;
		return ;
	}
	t = *alst;
	while (t->next && compar(t->next->content, newlst->content) <= 0)
		t = t->next;
	newlst->next = t->next;
	t->next = newlst;
}
