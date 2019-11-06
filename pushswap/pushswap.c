#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "pushswap.h"

void	show_stack(t_stack *t)
{
	if (t->a)
	{
		printf("%d\n", t->a->num);
		for (t_node *tmp = t->a->d; tmp != t->a; tmp = tmp->d)
			printf("%d\n", tmp->num);
	}
	else
		printf("Stack A empty\n");
	printf("-----\n");
	if (t->b)
	{
		printf("%d\n", t->b->num);
		for (t_node *tmp = t->b->d; tmp != t->b; tmp = tmp->d)
			printf("%d\n", tmp->num);
	}
	else
		printf("Stack B empty\n");
}

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
		show_stack(&t);
        if ((fd = (flags.filename ? open(flags.filename, O_WRONLY | O_CREAT) : 1)) < 0)
			file_error(flags.filename);
        //print_list(fd, sort(&a, &b, n));
        //clear_lists(a, b);
	}
    return 0;
}
