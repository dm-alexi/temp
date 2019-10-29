#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

int main(int ac, char **av)
{
	int			n;
	t_flags		flags;

	if (ac > 1 && (n = get_flags(ac, av, &flags)) > 0)
	{
		printf("%d", n);
	}
    return 0;
}
