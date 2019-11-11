#include "pushswap.h"
#include "libft/libft.h"

int		count_sorted(t_node *t, int rev)
{
	int		i;
	t_node	*tmp;

	tmp = t;
	i = 1;
	if (rev)
		while (tmp->num > tmp->d->num && ++i)
			tmp = tmp->d;
	else
		while (tmp->num < tmp->d->num && ++i)
			tmp = tmp->d;
	return (i);
}

void	sort3top(t_stack *t)
{
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
		int a_sorted = count_sorted(t->a, 0);
		int b_sorted = count_sorted(t->a, 1);
		if (a_sorted > 2 && a_sorted >= b_sorted)
			roll_a(t, a_sorted);
		else if (b_sorted > 2 && b_sorted > a_sorted)
			while (b_sorted--)
				exec(t, "pb");
		else
		{
			exec(t, "pb");
			exec(t, "pb");
			/*if (t->a->num > t->a->d->num)
				exec(t, "sa");*/
			if (t->b->num > t->b->d->num)
				exec(t, "sb");
		/*	exec(t, "ra");
			exec(t, "ra");*/
		}
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

	i = 0;
	if (t->a_count && t->b_count)
	{
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

int	moves_adjust_a(t_stack *t, int k)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (t->a_count && t->b_count)
	{
		tmp = t->a;
		while (!(tmp->num > k && tmp->u->num < k) && ++i)
		{
			tmp = tmp->d;
			if (tmp->num < tmp->u->num && (k > tmp->u->num || k < tmp->num))
				break ;
		}
	}
	return (i <= t->a_count / 2 ? i : i - t->a_count);
}
/*
void	moves_adjust_b(t_stack *t)
{
	int		i;
	int		m;
	t_node	*tmp;

	i = 0;
	if (t->a_count && t->b_count)
	{
		for (int j = 0; j < t->b_count; ++j)
		{

		}
	}
	return (i);
}
*/
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
	int		a_sorted;
	int		b_sorted;

	a_sorted = count_sorted(t->a, 0);
	b_sorted = count_sorted(t->b, 0);;
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
	/*	int	m = moves_adjust_a(t, t->b->num);
		int mu = moves_adjust_a(t, t->b->u->num);
		int md = moves_adjust_a(t, t->b->d->num);
		if (abs(mu) + 1 < abs(md) + 1 && abs(mu) + 1 < abs(m))
			while (abs(moves_adjust_a(t, t->b->u->num)) + 1 < abs(moves_adjust_a(t, t->b->num)))
				exec(t, "rb");
		else if (abs(md) + 1 < abs(mu) + 1 && abs(md) + 1 < abs(m))
			while (abs(moves_adjust_a(t, t->b->d->num)) + 1 < abs(moves_adjust_a(t, t->b->num)))
					exec(t, "rrb");*/
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
