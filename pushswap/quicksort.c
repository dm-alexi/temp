#include "pushswap.h"

int compar(const void *a, const void *b)
{
	const int 	*x;
	const int	*y;

	x = a;
	y = b;
	return (*x - *y);
}

void	sort3top_brev(t_stack *t)
{
	if (t->b->num < t->b->d->num)
		exec(t, "sb");
	if (t->b->num > t->b->d->num && t->b->d->num > t->b->d->d->num)
		return ;
	exec(t, "rb");
	exec(t, "sb");
	exec(t, "rrb");
	if (t->b->num < t->b->d->num)
		exec(t, "sb");
}

void 	qmerge_a(t_stack *t, int ac, int bc)
{
	int		n;
	int		i;
	t_node	*tmp;
	int c = 0;

	n = 0;
	while (c < bc)
	{
		i = 0;
		tmp = t->a;
		while (tmp->num < t->b->num && n < ac + c)
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
	roll_a(t, -n);
}

void 	qmerge_b(t_stack *t, int ac, int bc)
{
	int		n;
	int		i;
	t_node	*tmp;
	int c = 0;

	n = 0;
	while (c < ac)
	{
		i = 0;
		tmp = t->b;
		while (tmp->num > t->a->num && n < bc + c)
		{
			++i;
			++n;
			tmp = tmp->d;
		}
		if (!i)
			while (tmp->u->num < t->a->num && n > 0)
			{
				--i;
				--n;
				tmp = tmp->u;
			}
		roll_b(t, i);
		exec(t, "pb");
		++c;
	}
	roll_b(t, -n);
}

void sort_a_min(t_stack *t, int n)
{
	int		i = 0;

	if (n == 2 && t->a->num > t->a->d->num)
		exec(t, "sa");
	else if (n == 3)
		sort3top(t);
	else
	{
		while (count_sorted(t->a, 0) < n - i && n - i > 3)
		{
			exec(t, "pb");
			++i;
		}
		if (n - i == 3)
			sort3top(t);
		qmerge_a(t, n - i, i);
	}
	if (count_sorted(t->a, 0) < n)
		ft_printf("min A failed at %d %d\n", n, n - i);
}

void sort_b_min(t_stack *t, int n)
{
	int		i = 0;

	if (n == 2 && t->b->num < t->b->d->num)
		exec(t, "sb");
	else if (n == 3)
		sort3top_brev(t);
	else
	{
		while (count_sorted(t->b, 1) < n - i && n - i > 3)
		{
			exec(t, "pa");
			++i;
		}
		if (n - i == 3)
			sort3top_brev(t);
		qmerge_b(t, i, n - i);
	}
	if (count_sorted(t->b, 1) < n)
	{
		ft_printf("min B failed at %d %d\n", n, n - i);
		show_stacks(t);
	}
}

int get_median(t_node *t, int n)
{
	int		*arr;
	int		i;

	if (!(arr = (int*)malloc(sizeof(int) * n)))
		a_error("Error: memory allocation failed.\n");
	i = 0;
	while (i < n)
	{
		arr[i++] = t->num;
		t = t->d;
	}
	ft_qsort(arr, n, sizeof(int), compar);
	i = arr[n / 2 - 1];
	//ft_printf("median %d %d %d\n", arr[0], i, arr[n - 1]);
	free(arr);
	return (i);
}

void	quicksort_a(t_stack *t, int n)
{
	int		m;
	int		i;

	if (count_sorted(t->a, 0) >= n)
		return ;
	if (n == 2 && t->a->num > t->a->d->num)
		exec(t, "sa");
	else if (n == 3)
		sort3top(t);
	/*else if (n < 16)
		sort_a_min(t, n);*/
	else if (n >= 4)
	{
		m = get_median(t->a, n);
		i = 0;
		while (i++ < n)
			exec(t, t->a->num <= m ? "pb" : "ra");
		i = (n + 1) / 2;
		while (i--)
			exec(t, "rra");
		quicksort_a(t, (n + 1) / 2);
		quicksort_b(t, n - (n + 1) / 2);
		i = n / 2;
		while (i--)
			exec(t, "pa");
	}
}

void	quicksort_b(t_stack *t, int n)
{
	int		m;
	int		i;

	if (count_sorted(t->b, 1) >= n)
		return ;
	if (n == 2 && t->b->num < t->b->d->num)
		exec(t, "sb");
	else if (n == 3)
		sort3top_brev(t);
	/*else if (n < 16)
		sort_b_min(t, n);*/
	else if (n >= 4)
	{
		m = get_median(t->b, n);
		i = 0;
		while (i++ < n)
			exec(t, t->b->num > m ? "pa" : "rb");
		i = n / 2;
		while (i--)
			exec(t, "rrb");
		quicksort_b(t, (n / 2));
		quicksort_a(t, (n + 1) / 2);
		i = (n + 1) / 2;
		while (i--)
			exec(t, "pb");
	}
}
