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
	if (a_count == 1)
		add_prev(&last, exec(a, b, "ra"), 2);
	else if (a_count == 2 && (*a)->num > (*a)->d->num)
		add_prev(&last, exec(a, b, "sa"), 2);
	show_stack(*a);
	ft_printf("---\n");
	show_stack(*b);
	return (last);
}

t_list	*merge_sort(t_node **a, t_node **b, int n)
{
	t_list	*t;

	t = initial_split(a, b, n);
	return (t);
}
