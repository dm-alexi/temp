#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

int main(int ac, char **av)
{
	int			n;
	t_flags		flags;
	t_node		*a;

	if (ac > 1 && (n = get_flags(ac, av, &flags)) > 0)
	{
		a = get_args(n, av + ac - n);
		for (t_node *t = a->u; t != a; t = t->u)
			printf("%d ", t->num);
		printf("%d", a->num);
	}
    return 0;
}
