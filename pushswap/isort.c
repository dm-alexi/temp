#include "pushswap.h"

void	sort3top_b(t_stack *t)
{
	if (t->b->num > t->b->d->num)
		exec(t, "sb");
	if (t->b->num < t->b->d->num && t->b->d->num < t->b->d->d->num)
		return ;
	exec(t, "rb");
	exec(t, "sb");
	exec(t, "rrb");
	if (t->b->num > t->b->d->num)
		exec(t, "sb");
}

void	isort_a(t_stack *t, int n)
{
	int		*arr;
	t_node	*tmp = t->a;
	int		i;

	if (!(arr = (int*)malloc(sizeof(int) * n)))
		a_error("Error: memory allocation failed.\n");
	i = 0;
	while (i < n)
	{
		arr[i++] = tmp->num;
		tmp = tmp->d;
	}

}

/*
void	isort_a(t_stack *t, int n)
{
	int 	i;

	if (n == 2 && t->a->num > t->a->d->num)
		exec(t, "sa");
	else if (n == 3)
		sort3top(t);
	else if (n > 3)
	{
		i = 0;
		while (i < n / 2)
		{
			exec(t, "pb");
			++i;
		}
		isort_a(t, n - i);
		isort_b(t, i);
		merge_a(t, n - i, i);
	}
}

void	isort_b(t_stack *t, int n)
{
	int 	i;

	if (n == 2 && t->b->num > t->b->d->num)
		exec(t, "sb");
	else if (n == 3)
		sort3top_b(t);
	else if (n > 3)
	{
		i = 0;
		while (i < n / 2)
		{
			exec(t, "pa");
			++i;
		}
		isort_b(t, n - i);
		isort_a(t, i);
		merge_b(t, i, n - i);
	}
}*/
