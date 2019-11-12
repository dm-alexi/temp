#include "libft/libft.h"
#include "pushswap.h"

void rsort(t_stack *t)
{
    t_node	*tmp;
    int		i;

    tmp = t->a->d;
    i = 0;
    while (++i && tmp->num > tmp->u->num)
		tmp = tmp->d;
	if (i > t->a_count / 2)
		i = -(t->a_count - i);
	roll(t, i, 0);
}

void	sort_3(t_stack *t)
{
	if (sorted(t->a))
		return ;
	else if (rsorted(t->a, 0))
		rsort(t);
	else if (t->a->num < t->a->d->num && t->a->num < t->a->d->d->num)
	{
		exec(t, "sa");
		exec(t, "ra");
	}
	else if (t->a->num > t->a->d->num && t->a->num > t->a->d->d->num)
	{
		exec(t, "sa");
		exec(t, "rra");
	}
	else
		exec(t, "sa");
}
/*
void	sort_min(t_stack *t)
{
	while (!rsorted(t->a, 0) && t->a_count > 3)
		exec(t, "pb");
	if (!rsorted(t->a, 0))
		sort_3(t);
	final_merge(t);
	if (!sorted(t->a))
		rsort(t);
}*/

void	sort(t_stack *t)
{
    if (sorted(t->a))
		return ;
	else if (rsorted(t->a, 0))
		rsort(t);
    else if (t->a_count == 3)
		sort_3(t);
	/*else if (t->a_count <= 7)
		sort_min(t);*/
	else
		dsort(t);
}

