#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pushswap.h"

int		sorted(t_node *a)
{
	t_node	*t;

	if (a)
	{
		t = a->d;
		while (t != a)
			if (t->num <= t->u->num)
				return (0);
	}
	return (1);
}

void	clear_lists(t_node *a, t_node *b)
{
	t_node	*t;

	if ((t = a))
		while ((t = t->d) != a->d)
			free(t->u);
	if ((t = b))
		while ((t = t->d) != b->d)
			free(t->u);

}

void	show_stack(t_node *a)
{
	printf("%d\n", a->num);
	for (t_node *t = a->d; t != a; t = t->d)
		printf("%d\n", t->num);
}

int 	main(int ac, char **av)
{
	int			n;
	int			fd;
	t_flags		flags;
	t_node		*a;
	t_node		*b;

	if (ac > 1 && (n = get_flags(ac, av, &flags)) > 0)
	{
		a = get_args(n, av + ac - n);
		show_stack(a);
        if ((fd = (flags.filename ? open(flags.filename, O_RDONLY) : 0)) < 0)
			file_error(flags.filename);
		b = NULL;
		while ((n = get_com(fd, &a, &b)))
			if (n == -1)
				error();
        write(1, sorted(a) && !b ? "OK\n" : "KO\n", 3);
        show_stack(a);
        clear_lists(a, b);
	}
    return 0;
}
