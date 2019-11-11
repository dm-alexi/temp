#include "pushswap.h"
/*
int d[MAXN], p[MAXN]; // константа MAXN равна наибольшему возможному значению n

for (int i=0; i<n; ++i) {
	d[i] = 1;
	p[i] = -1;
	for (int j=0; j<i; ++j)
		if (a[j] < a[i])
			if (1 + d[j] > d[i]) {
				d[i] = 1 + d[j];
				p[i] = j;
			}
}

int ans = d[0],  pos = 0;
for (int i=0; i<n; ++i)
	if (d[i] > ans) {
		ans = d[i];
		pos = i;
	}*/

//int maxlen(int *a, int n, )
/*
//longest up
int		*long_up(t_node *t, int n)
{
	int		*arr;
	int		i;
	int *res = NULL;
	//int *fin = (int*)malloc(sizeof(int) * n);
	int len = 0;

	if (!(arr = (int*)malloc(sizeof(int) * n)))
		mem_error();
	i = 0;
	while (i < n)
	{
		arr[i++] = t->num;
		t = t->d;
	}
	if ((i = maxlen(arr, n, res)) > len)
	{
		for (int j = 0; j < i; ++j)
			ft_printf("%d ", res[j]);
	}
	return (res);
}
*/
