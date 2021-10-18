/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:37:41 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 21:52:02 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Stable O(n^2) sort, no memory allocation
*/

void	ft_lstsort(t_list **alst, int (*compar)(const void*, const void*))
{
	t_list	*t;
	t_list	*tmp;

	if (!alst || !compar)
		return ;
	t = NULL;
	while (*alst)
	{
		tmp = (*alst)->next;
		ft_lstadd_sorted(&t, *alst, compar);
		*alst = tmp;
	}
	*alst = t;
}
