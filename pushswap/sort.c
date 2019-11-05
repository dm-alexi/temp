#include "libft/libft.h"
#include "pushswap.h"

static char *generate(const char *s, int n)
{
	char	*str;

	if (!(str = (char*)malloc(ft_strlen(s) * n + 1)))
		a_error("Error: memory allocation failed.\n");
	*str = '\0';
	while (n--)
		ft_strcat(str, s);
	return (str);
}

static char *rsort(t_node *a, int n)
{
    t_node	*t;
    int		i;

    t = a->d;
    i = 0;
    while (++i && t->num > t->u->num)
		t = t->d;
	if (i <= n / 2)
		return (generate("ra\n", i));
	else
		return (generate("rra\n", n - i));
}

static char	*sort_3(t_node *a)
{
	if (a->num < a->d->num && a->num < a->d->d->num)
		return(ft_strdup("sa\nra\n"));
	if (a->num > a->d->num && a->num > a->d->d->num)
		return(ft_strdup("sa\nrra\n"));
	return (ft_strdup("sa\n"));
}

char	*sort(t_node **a, t_node **b, int n)
{
    char	*s;

    //check return statement
    if (sorted(*a))
		s = NULL;
	else if (rsorted(*a, 0))
		s = rsort(*a, n);
    else if (n == 3)
		s = sort_3(*a);
	else
		s = ft_strdup("can't sort");
	return (s);
}
