#include <stdlib.h>
#include "libft.h"

void  ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    t_list *t;
    t_list *tmp;

    if (!alst || !del)
        return;
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
