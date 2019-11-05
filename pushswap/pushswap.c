#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "pushswap.h"

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
		a = get_args(n, av + ac - n, &n);
		show_stack(a);
        if ((fd = (flags.filename ? open(flags.filename, O_WRONLY | O_CREAT) : 1)) < 0)
			file_error(flags.filename);
		b = NULL;
		//printf("--%d--\n", n);
        print_list(fd, sort(&a, &b, n));
        clear_lists(a, b);
	}
    return 0;
}
