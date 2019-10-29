#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

int main(int ac, char **av)
{
	int			n;
	t_flags		flags;
	int			*a;

	if (ac > 1 && (n = get_flags(ac, av, &flags)) > 0)
	{
		a = get_args(n, av + ac - n);
		/*for (int i = 0; i < n; ++i)
			printf("%d ", a[i]);*/
	}
    return 0;
}
