#include "libft.h"

void	ft_lstadd_sorted(t_list **alst, t_list *new,
    int (*compar)(const void*, const void*))
{
	t_list *t;

	if (!alst || !new || !compar)
        return ;
    if (!*alst || compar((*alst)->content, new->content) > 0)
    {
		new->next = *alst;
		*alst = new;
		return ;
	}
	t = *alst;
	while (t->next && compar(t->next->content, new->content) <= 0)
        t = t->next;
    new->next = t->next;
    t->next = new;
}
