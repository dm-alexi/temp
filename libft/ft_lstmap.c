#include <stdlib.h>
#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
    t_list *t;
    t_list *tmp;

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
        };
        tmp = tmp->next;
        lst = lst->next;
    }
    tmp->next = NULL;
    return (t);
}
