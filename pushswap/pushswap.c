#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "pushswap.h"

void	print_log(t_stack *t)
{
	t_list	*lst;
	int		n;

	n = 0;
	lst = t->start;
	if (!lst)
		ft_printf("No list!");
	while (lst && ++n)
	{
		ft_printf("%s ", lst->content);
		lst = lst->next;
	}
	ft_printf("\nCom len = %d\n", n);
}

void	show_stacks(t_stack *t)
{
	if (t->a)
	{
		ft_printf("%d\n", t->a->num);
		for (t_node *tmp = t->a->d; tmp != t->a; tmp = tmp->d)
			ft_printf("%d\n", tmp->num);
	}
	else
		ft_printf("Stack A empty\n");
	ft_printf("-----\n");
	if (t->b)
	{
		ft_printf("%d\n", t->b->num);
		for (t_node *tmp = t->b->d; tmp != t->b; tmp = tmp->d)
			ft_printf("%d\n", tmp->num);
	}
	else
		ft_printf("Stack B empty\n");
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
		show_stacks(&t);
		ft_printf("--------\n");
        if ((fd = (flags.filename ? open(flags.filename, O_WRONLY | O_CREAT) : 1)) < 0)
			file_error(flags.filename);
		sort(&t);
		print_log(&t);
		show_stacks(&t);
        clear_stacks(&t);
	}
    return 0;
}
