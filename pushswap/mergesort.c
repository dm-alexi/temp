#include "pushswap.h"
#include "libft/libft.h"

void	sort3top(t_stack *t)
{
    /*if (t->a_count == 3)
    {
    	sort_3(t);
    	return ;
    }*/
	if (t->a->num > t->a->d->num)
		exec(t, "sa");
	if (t->a->num < t->a->d->num && t->a->d->num < t->a->d->d->num)
		return ;
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
		if (t->b->num > t->b->d->num)
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
		roll_a(t, i);
	}
}

void	merge_a(t_stack *t, int a_sorted, int b_sorted)
{
	int		n;
	int		i;
	int		sum;
	t_node	*tmp;
	int c = 0;

	sum = a_sorted + b_sorted;
	n = 0;
	while (c < b_sorted)
	{
		i = 0;
		tmp = t->a;
		while (tmp->num < t->b->num && n < a_sorted + c)
		{
			++i;
			++n;
			tmp = tmp->d;
		}
		if (!i)
			while (tmp->u->num > t->b->num && n > 0)
			{
				--i;
				--n;
				tmp = tmp->u;
			}
		roll_a(t, i);
		exec(t, "pa");
		++c;
	}
	roll_a(t, sum - n);
}

void	merge_b(t_stack *t, int a_sorted, int b_sorted)
{
	int		n;
	int		i;
	int		sum;
	t_node	*tmp;
	int	c;

	c = 0;
	sum = a_sorted + b_sorted;
	n = 0;
	while (a_sorted--)
	{
		i = 0;
		tmp = t->b;
		while (tmp->num < t->a->num && n < b_sorted + c)
		{
			++i;
			++n;
			tmp = tmp->d;
		}
		if (!i)
			while (tmp->u->num > t->a->num && n > 0)
			{
				--i;
				--n;
				tmp = tmp->u;
			}
		roll_b(t, i);
		exec(t, "pb");
		++c;
	}
	roll_b(t, sum - n);
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
	while (tmp->num < tmp->d->num && ++b_sorted)
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
	while (!rsorted(t->a, 0) && t->a_count > 3)
		merge(t);
	if (!rsorted(t->a, 0))
		sort_3(t);
	print_log(t);
	final_merge(t);
	if (!sorted(t->a))
		rsort(t);
}
