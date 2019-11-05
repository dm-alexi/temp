#include "pushswap.h"
#include "libft/libft.h"

t_list	*initial(t_node **a, t_node **b, int n, t_list *start)
{
	t_list	*last;
	int		a_num;

	a_num = n;
	last = start;
    while (a_num > (n + 1) / 2)
	{
		add_next(&last, exec(a, b, "pb"), 2);
		add_next(&last, exec(a, b, "pb"), 2);
        //if ()
	}
}

t_list	*merge_sort(t_node **a, t_node **b, int n)
{
	t_list	*start;
	t_list	*t;

	t = NULL;
	t = ft_lstnew("can't", 6);
	return (t);
}
