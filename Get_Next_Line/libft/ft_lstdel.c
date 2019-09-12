/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:33:31 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/07 11:35:45 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*t;
	t_list	*tmp;

	if (!alst || !del)
		return ;
	t = *alst;
	while (t)
	{
		tmp = t->next;
		del(t->content, t->content_size);
		free(t);
		t = tmp;
	}
	*alst = NULL;
}
