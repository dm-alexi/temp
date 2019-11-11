#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "pushswap.h"

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
        if ((fd = (flags.filename ? open(flags.filename, O_RDONLY) : 0)) < 0)
			file_error(flags.filename);
		b = NULL;
		while ((n = get_com(fd, &t)))
			;
        write(1, sorted(a) && !b ? "OK\n" : "KO\n", 3);
        show_stacks(a);
        clear_lists(a, b);
	}
    return 0;
}
