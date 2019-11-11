#include "pushswap.h"

int compar(const void *a, const void *b)
{
	const int 	*x;
	const int	*y;

	x = a;
	y = b;
	return (*x - *y);
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
		merge_a(t, n - i, i);
		while (t->a->num > t->a->u->num)
			exec(t, "rra");
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
		free(arr);
	ft_printf("median %d\n", i);
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
	/*else if (n < 7)
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
	else if (n > 3)
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
