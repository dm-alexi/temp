/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:34:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/07 11:35:01 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*t;
	t_list	*tmp;

	if (!lst || !f || !(t = f(lst)))
		return (NULL);
	tmp = t;
	while (lst->next)
	{
		if (!(tmp->next = f(lst->next)))
		{
			while (t)
			{
				tmp = t->next;
				free(t->content);
				free(t);
				t = tmp;
			}
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (t);
}
