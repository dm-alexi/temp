#include "pushswap.h"

int compar(const void *a, const void *b)
{
	const int 	*x;
	const int	*y;

	x = a;
	y = b;
	return (*x - *y);
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
	i = arr[n / 2];
	free(arr);
	return (i);
}

void	quicksort_a(t_stack *t, int n)
{
	int		m;
	int		i;
	
	if (n == 2 && t->a->num > t->a->d->num)
		exec(t, "sa");
	else if (n == 3)
		sort3top(t);
	else if (n > 3)
	{
		m = get_median(t->a, n);
		i = 0;
		while (i++ < n)
			exec(t, t->a->num < m ? "pb" : "ra");
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
	
	if (n == 2 && t->b->num < t->b->d->num)
		exec(t, "sb");
	else if (n == 3)
		sort3top_brev(t);
	else if (n > 3)
	{
		show_stacks(t);
		m = get_median(t->b, n);
		ft_printf("Median = %d\n", m);
		i = 0;
		while (i++ < n)
			exec(t, t->b->num >= m ? "pa" : "rb");
		i = (n + 1) / 2;
		while (i--)
			exec(t, "rrb");
		quicksort_b(t, (n + 1) / 2);
		quicksort_a(t, n - (n + 1) / 2);
		i = n / 2;
		while (i--)
			exec(t, "pb");
	}
}