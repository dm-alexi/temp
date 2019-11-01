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

t_node	*add(t_node **cur, t_node *t)
{
	if (!t)
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

t_node	*pop(t_node **cur)
{
	t_node	*t;


	if (!*cur)
		return (NULL);
	t = *cur;
	if ((*cur)->d == *cur)
		*cur = NULL;
	else
	{
		*cur = (*cur)->d;
		(*cur)->u = (*cur)->u->u;
		(*cur)->u->d = (*cur);
	}
	return (t);
}

void	push(t_node **to, t_node **from)
{
	add(to, pop(from));
}

void	swap(t_node *t)
{
	int		n;

	if (t && t->d != t)
	{
		n = t->num;
		t->num = t->d->num;
		t->d->num = n;
	}
}
