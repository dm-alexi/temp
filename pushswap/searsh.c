#include "pushswap.h"

//longest up
int		*long_up(t_node *t, int n)
{
	int		*arr;
	int		i;
	
	if (!(arr = (int*)malloc(sizeof(int) * n)))
		mem_error();
	i = 0;
	while (i < n)
	{
		arr[i++] = t->num;
		t = t->d;
	}

}

int		maxlen(int *uns, int *s, int n, int *res)
{
	int len = 0;;
	int *res = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; ++i)
	{
		for
	}
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