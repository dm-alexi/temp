#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "pushswap.h"

int 	main(int ac, char **av)
{
	int			n;
	int			fd;
	t_flags		flags;
	t_stack		t;

	if (ac > 1 && (n = get_flags(ac, av, &flags)) > 0)
	{
		ft_bzero(&t, sizeof(t));
		t.a = get_args(n, av + ac - n, &n);
		t.a_count = n;
		show_stacks(&t);
        if ((fd = (flags.filename ? open(flags.filename, O_WRONLY | O_CREAT) : 1)) < 0)
			file_error(flags.filename);
		sort(&t);
		print_log(&t);
		//reduce(t.start);
		//print_log(&t);
		show_stacks(&t);
        clear_stacks(&t);
	}
    return 0;
}
