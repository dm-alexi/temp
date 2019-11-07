#include "pushswap.h"
#include "libft/libft.h"

void	sort3top(t_stack *t)
{
    if (t->a->num > t->a->d->num && t->a->num > t->a->d->d->num)
		exec(t, "sa");
	if (t->a->num > t->a->d->num)
		exec(t, "sa");
	if (t->a->num < t->a->d->num && t->a->d->num < t->a->d->d->num)
		return;
	exec(t, "ra");
	exec(t, "sa");
	exec(t, "rra");
	if (t->a->num > t->a->d->num)
		exec(t, "sa");
}

void	initial_split(t_stack *t)
{
    while (t->a_count - t->b_count >= 4)
	{
		exec(t, "pb");
		exec(t, "pb");
        if (t->a->num > t->a->d->num)
			exec(t, "sa");
		if (t->b->num < t->b->d->num)
			exec(t, "sb");
		exec(t, "ra");
		exec(t, "ra");
	}
	if (t->a_count - t->b_count == 1 || t->a_count - t->b_count == 3)
		sort3top(t);
	else if (t->a_count - t->b_count == 2 && t->a->num > t->a->d->num)
		exec(t, "sa");
	show_stacks(t);
}

void	merge(t_stack *t)
{
	t_node	*tmp;
	int		a_sorted;
	int		b_sorted;

	tmp = t->a;
	a_sorted = 1;
	while (t->num < t->d->num && ++a_sorted)
		t = t->d;
	tmp = t->b;
	b_sorted = 1;
	while (t->num < t->d->num && ++b_sorted)
		t = t->d;

}

void	merge_sort(t_stack *t)
{
	initial_split(t);
	//if (rsorted(t->a, 0))
	//	final_merge(t);
}
