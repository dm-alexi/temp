#include "pushswap.h"

int		sorted(t_node *a)
{
	t_node	*t;

	if (a)
	{
		t = a->d;
		while (t != a)
		{
			if (t->num <= t->u->num)
				return (0);
			t = t->d;
		}
	}
	return (1);
}
