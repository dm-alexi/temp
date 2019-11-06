#include "pushswap.h"
#include "libft/libft.h"

t_list	*initial_split(t_node **a, t_node **b, int n)
{
	t_list	*last;
	int		a_count;

	last = NULL;
	a_count = n;
    while (a_count > 2)
	{
		add_prev(&last, exec(a, b, "pb"), 2);
		add_prev(&last, exec(a, b, "pb"), 2);
        if ((*a)->num > (*a)->d->num)
			add_prev(&last, exec(a, b, "sa"), 2);
		if ((*b)->num < (*b)->d->num)
			add_prev(&last, exec(a, b, "sb"), 2);
		add_prev(&last, exec(a, b, "ra"), 2);
		add_prev(&last, exec(a, b, "ra"), 2);
		a_count -= 4;
	}
	if (a_count == 1 && (*a)->num > (*a)->d->num)
		add_prev(&last, exec(a, b, "ra"), 2);
	else if (a_count == 2 && (*a)->num > (*a)->d->num)
		add_prev(&last, exec(a, b, "sa"), 2);
	show_stack(*a);
	ft_printf("---\n");
	show_stack(*b);
	ft_printf("=======\n");
	return (last);
}

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

t_list	*connect(t_list *f, t_list *s)
{
	t_list	*t;

	t = f;
	while (t->next)
		t = t->next;
	t->next = s;
	return (f);
}

t_list	*merge_sort(t_node **a, t_node **b, int n)
{
	t_list	*t;

	t = initial_split(a, b, n);
	t = connect(merge(a, b), t);
	//if (rsortet(a))
	show_stack(*a);
	ft_printf("---\n");
	show_stack(*b);

	return (t);
}
