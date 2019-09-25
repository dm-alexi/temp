#include "fillit.h"

// magic const here
static int	count_positions(int type, int sq)
{
	if (type <= 2)
		return (sq * (sq - 3) + 1);
	if (type == 9)
		return ((sq - 1) * (sq - 1) + 1);
	return ((sq - 1) * (sq - 2) + 1);
}

// magic const here
static int	valid(int i, int j, int type, int sq)
{
	if (type == 1)
		return (i <= sq - 4);
	if (type == 2)
		return (j <= sq - 4);
    if (type == 9)
		return (i <= sq - 2 && j <= sq - 2);
	if (type == 3 || type == 5 || type == 7 || type == 10 || type == 13 ||
		type == 14 || type == 16 || type == 19)
		return (i <= sq - 3 && j <= sq - 2);
	return (i <= sq - 2 && j <= sq - 3);
}

// magic const here
static int	*arr_fill(int n, int num, int t, int sq)
{
	int		*res;
	int		i;

	if (!(res = (int*)malloc(sizeof(int) * 5)))
		return (NULL);
	i = 1;
	if (t <= 13)
		res[i++] = n + num + 1;
	if (!(t == 1 || t == 5 || t == 7 || t == 10 || t == 12 || t == 18))
		res[i++] = n + 1 + num + 1;
	if (t == 2 || t == 4 || t == 6 || t == 8 || t == 15 || t == 18)
		res[i++] = n + 2 + num + 1;
	if (!(t == 2 || t == 6 || t == 8 || t == 11 || t == 13 || t == 19))
		res[i++] = n + sq + num + 1;
	 if (t > 4 && t != 7 && t != 8)
		res[i++] = n + sq + 1 + num + 1;
	if (t == 8 || t == 11 || t == 12 || t == 17 || t == 18)
		res[i++] = n + sq + 2 + num + 1;
	if (t == 1 || t == 3 || t == 5 || t == 7 || t == 14 || t == 19)
		res[i++] = n + 2 * sq + num + 1;
	if (t == 7 || t == 10 || t == 13 || t == 16 || t == 19)
		res[i++] = n + 2 * sq + 1 + num + 1;
	if (t == 1)
		res[i] = n + 3 * sq + num + 1;
	if (t == 2)
		res[i] = n + 3 + num + 1;
	return (res);
}

int			**clear_rows(int **arr)
{
    int		**tmp;

    tmp = arr;
    while (*tmp)
		free(*tmp++);
	free(arr);
	return (NULL);
}

int			**get_rows(int ord, int num, int type, int sq)
{
	int		n;
	int		i;
	int		j;
	int		k;
	int		**arr;

	n = count_positions(type, sq);
    if (!(arr = (int**)malloc(sizeof(int*) * n)))
		exit(1);
	k = 0;
	i = 0;
	while (i < sq)
	{
		j = 0;
		while (j < sq)
		{
			if (valid(i, j, type, sq))
			{
				if (!(arr[k] = arr_fill(i * sq + j, num, type, sq)))
					exit(1);
				arr[k++][0] = ord;
			}
			++j;
		}
		++i;
	}
	arr[k] = NULL;
	return (arr);
}
