#include "pushswap.h"
#include "libft/libft.h"

t_node	*new_node(int n)
{
	t_node	*t;

	if (!(t = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
    t->num = n;
    t->u = t;
    t->d = t;
    return (t);
}

t_node	*push(t_node **cur, int n)
{
	t_node	*t;

	if (!(t = new_node(n)))
		return (NULL);
	if (*cur)
	{
		t->u = (*cur)->u;
		t->d = *cur;
		(*cur)->u->d = t;
		(*cur)->u = t;
	}
	*cur = t;
	return (t);
}
