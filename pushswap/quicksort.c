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

void	quicksort(t_stack *t)
{
	
}