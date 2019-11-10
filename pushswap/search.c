#include "pushswap.h"

/*
int		maxlen(int *uns, int *s, int n, int *res)
{
	int len = 0;;
	int *res = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; ++i)
	{
		for
	}
}*/

int maxlen(int *arr, int n, int *res)
{
	int *p = (int*)ft_memalloc(sizeof(int) * n);
	int *m = (int*)ft_memalloc(sizeof(int) * n + 1);
	for (int i = 0; i < n + 1; ++i)
		m[i] = 1;
	int l = 0;

	for (int i = 0; i < n; ++i)
	{
		int lo = 1, hi = l, mid, newl;
		while (lo <= hi)
		{
			mid = (lo + hi + 1) / 2;
			if (arr[m[mid]] < arr[i])
				lo = mid + 1;
			else
				hi = mid - 1;
			
		}
		newl = lo;
		p[i] = m[newl - 1];
		if (newl > l)
			l = newl;
	}
	res = (int*)malloc(sizeof(int) * n);
	int k = m[l];
	for (int i = l - 1; i >= 0; --i)
	{
		res[i] = arr[k];
		k = p[k];
	}
	return (l);
}


/*
P = array of length N
M = array of length N + 1
L = 0
for i in range 0 to N-1:
  lo = 1
  hi = L
  while lo ≤ hi:
    mid = ceil((lo+hi)/2)
    if X[M[mid]] < X[i]:
      lo = mid+1
    else:
      hi = mid-1
  newL = lo
  P[i] = M[newL-1]
  M[newL] = i
  if newL > L:
    L = newL
S = array of length L
k = M[L]
for i in range L-1 to 0:
  S[i] = X[k]
  k = P[k]
return S
*/
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