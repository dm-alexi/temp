#include "pushswap.h"
#include "libft/libft.h"
/*
t_list	*initial_split(t_stack *t)
{
	t_list	*last;

	last = NULL;
    while (t->a_count - t->b_count >= 4)
	{
		add_prev(&last, exec(t, "pb"), 2);
		add_prev(&last, exec(t, "pb"), 2);
        if (t->a->num > t->a->d->num)
			add_prev(&last, exec(t, "sa"), 2);
		if (t->b->num < t->b->d->num)
			add_prev(&last, exec(t, "sb"), 2);
		add_prev(&last, exec(t, "ra"), 2);
		add_prev(&last, exec(t, "ra"), 2);
	}/*
	if (t->a_count == 1 && t->a->num > t->a->d->num)
		add_prev(&last, exec(t, "ra"), 2);
	else if (t->a_count == 2 && t->a->num > t->a->d->num)
		add_prev(&last, exec(t, "sa"), 2);
	show_stack(t);
	return (last);
}*/
/*
t_list	*merge_a(t_node **a, t_node **b, int a_count, int b_count)
{
    t_list	*t;
    int		n;

    t = NULL;
    n = 0;
    while (b_count--)
	{
		while ((*a)->num < (*b)->num && n < a_count)
		{
			add_prev(&t, exec(a, b, "ra"), 2);
			++n;
		}
		while ((*a)->u->num > (*b)->num && n > 0)
		{
			add_prev(&t, exec(a, b, "rra"), 2);
			--n;
		}
		add_prev(&t, exec(a, b, "pa"), 2);
	}
	return (t);
}

t_list	*merge_b(t_node **a, t_node **b, int a_count, int b_count)
{
    t_list	*t;
    int		n;

    t = NULL;
    n = 0;
    while (a_count--)
	{
		while ((*a)->num > (*b)->num && n < b_count)
		{
			add_prev(&t, exec(a, b, "rb"), 2);
			++n;
		}
		while ((*a)->num < (*b)->u->num && n > 0)
		{
			add_prev(&t, exec(a, b, "rrb"), 2);
			--n;
		}
		add_prev(&t, exec(a, b, "pb"), 2);
	}
	return (t);
}
*/
t_list	*merge(t_node **a, t_node **b)
{
	t_node	*t;
	t_list	*tmp;
	int		a_count;
	int		b_count;

	t = *a;
	a_count = 1;
	while (t->num < t->d->num)
	{
		++a_count;
		t = t->d;
	}
	t = *b;
	b_count = 1;
	while (t->num > t->d->num)
	{
		++b_count;
		t = t->d;
	}
	/*tmp = (a_count >= b_count) ? merge_a(a, b, a_count, b_count) :
		merge_b(a, b, a_count, b_count);*/

	return (tmp);
}
/*
t_list	*merge_sort(t_stack *t)
{
	t_list *tmp = initial_split(t);

	return (tmp);
}
*/
