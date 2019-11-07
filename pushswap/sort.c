#include "libft/libft.h"
#include "pushswap.h"

static void rsort(t_stack *t)
{
    t_node	*tmp;
    int		i;

    tmp = t->a->d;
    i = 0;
    while (++i && tmp->num > tmp->u->num)
		tmp = tmp->d;
	if (i <= t->a_count / 2)
		while (i--)
			exec(t, "ra");
	else
		while (i++ < t->a_count)
			exec(t, "rra");
}

static void	sort_3(t_stack *t)
{
	if (t->a->num < t->a->d->num && t->a->num < t->a->d->d->num)
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

void	sort(t_stack *t)
{
    if (sorted(t->a))
		return ;
	else if (rsorted(t->a, 0))
		rsort(t);
    else if (t->a_count == 3)
		sort_3(t);
	/*else
		t = merge_sort(t, n);*/
}

