#include "pushswap.h"
#include "libft/libft.h"

void	sort3top(t_stack *t)
{
    if (t->a_count == 3)
    {
    	sort_3(t);
    	return ;
    }
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

void	adjust_a(t_stack *t)
{
	int		i;
	t_node	*tmp;

	if (t->a_count && t->b_count)
	{
		i = 0;
		tmp = t->a;
		while (!(tmp->num > t->b->num && tmp->u->num < t->b->num) && ++i)
		{
			tmp = tmp->d;
			if (tmp->num < tmp->u->num && (t->b->num > tmp->u->num || t->b->num < tmp->num))
				break ;
		}
		if (i <= t->a_count / 2)
			while (i--)
				exec(t, "ra");
		else
			while (i++ < t->a_count)
				exec(t, "rra");
	}
}
/*
int		adjust_b(t_stack *t)
{
	int		n;
	int		i;
	t_node	*tmp;

	if (t->a_count && t->b_count)
	{
		n = 0;
		i = 0;
		tmp = t->b;
		while (!(tmp->num > t->a->num && tmp->u->num < t->a->num) && ++i)
			tmp = tmp->d;
		n = i;
		if (i <= t->b_count / 2)
		{
			while (i--)
				exec(t, "rb");
			return (n);
		}
		while (i++ < t->b_count)
			exec(t, "rrb");
		return (n - t->b_count);
	}
	return (0);
}
*/
void	merge_a(t_stack *t, int a_sorted, int b_sorted)
{
	int		n;
	int		sum;

	sum = a_sorted + b_sorted;
	n = 0;
	while (b_sorted--)
	{
		while (t->a->num < t->b->num && n < a_sorted)
		{
			++n;
			exec(t, "ra");
		}
		while (t->a->u->num > t->b->num && n > 0)
		{
			--n;
			exec(t, "rra");
		}
		exec(t, "pa");
	}
	while (n++ < sum)
		exec(t, "ra");
}

void	merge_b(t_stack *t, int a_sorted, int b_sorted)
{
	int		n;
	int		sum;

	sum = a_sorted + b_sorted;
	n = 0;
	while (a_sorted--)
	{
		while (t->b->num > t->a->num && n < b_sorted)
		{
			++n;
			exec(t, "rb");
		}
		while (t->b->u->num < t->a->num && n > 0)
		{
			--n;
			exec(t, "rrb");
		}
		exec(t, "pb");
	}
	while (n++ < sum)
		exec(t, "rb");
}

void	merge(t_stack *t)
{
	t_node	*tmp;
	int		a_sorted;
	int		b_sorted;

	tmp = t->a;
	a_sorted = 1;
	while (tmp->num < tmp->d->num && ++a_sorted)
		tmp = tmp->d;
	tmp = t->b;
	b_sorted = 1;
	while (tmp->num > tmp->d->num && ++b_sorted)
		tmp = tmp->d;
	ft_printf("sorted: %d %d\n", a_sorted, b_sorted);
	if (t->a_count - a_sorted < t->b_count - b_sorted)
		merge_a(t, a_sorted, b_sorted);
	else
		merge_b(t, a_sorted, b_sorted);
	show_stacks(t);
	ft_printf("-------\n");
}

void	final_merge(t_stack *t)
{
	while (t->b_count)
	{
		adjust_a(t);
		exec(t, "pa");
	}
}

void	merge_sort(t_stack *t)
{
	initial_split(t);
	while (!rsorted(t->a, 0))
		merge(t);
	final_merge(t);
	//show_stacks(t);
	if (!sorted(t->a))
		rsort(t);
}
