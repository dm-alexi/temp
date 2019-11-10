#include "pushswap.h"

//longest up
int		*long_up(t_node *t, int n)
{
	t_node	*tmp;
	int		*p;
	int		*m;
	int		*s;
	int		l;

	if (!(p = (int*)malloc(sizeof(int) * n)) ||
	!(s = (int*)malloc(sizeof(int) * n)) ||
	!(m = (int*)malloc(sizeof(int) * (n + 1))))
		mem_error();
	l = 0;
	for (int i = 0; i < n; ++i)
	{
		int lo = 1;
		int hi = l;
		while (lo < hi)
		{
			int mid = (lo + hi + 1) / 2;
			if ()
		}
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