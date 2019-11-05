#include "libft/libft.h"
#include "pushswap.h"

static t_list	*generate(const char *s, int n)
{
	t_list	*t;
	t_list	*tmp;
	int		len;

	len = ft_strlen(s) + 1;
	if (!(t = ft_lstnew(s, len)))
		a_error("Error: memory allocation failed.\n");
	while (--n)
	{
		if (!(tmp = ft_lstnew(s, len)))
			a_error("Error: memory allocation failed.\n");
		ft_lstadd(&t, tmp);
	}
	return (t);
}

static t_list	*rsort(t_node *a, int n)
{
    t_node	*t;
    int		i;

    t = a->d;
    i = 0;
    while (++i && t->num > t->u->num)
		t = t->d;
	return (i <= n / 2 ? generate("ra", i) : generate("rra", n - i));
}

static t_list	*sort_3(t_node *a)
{
	t_list	*t;
	t = NULL;

	if (a->num < a->d->num && a->num < a->d->d->num)
	{
		add_prev(&t, "sa", 3);
		add_prev(&t, "ra", 3);
	}
	else if (a->num > a->d->num && a->num > a->d->d->num)
	{
		add_prev(&t, "sa", 3);
		add_prev(&t, "rra", 4);
	}
	else
		add_prev(&t, "sa", 3);
	return (t);
}

t_list	*sort(t_node **a, t_node **b, int n)
{
    t_list	*t;

    //check return statement
    if (sorted(*a))
		t = NULL;
	else if (rsorted(*a, 0))
		t = rsort(*a, n);
    else if (n == 3)
		t = sort_3(*a);
	else
		t = merge_sort(a, b, n);
	return (t);
}
