#include <fcntl.h>
#include <limits.h>
#include "pushswap.h"
#include "libft/libft.h"

int		get_flags(int ac, char **av, t_flags *flags)
{
    int		i;
    char	*s;

    i = 0;
    ft_bzero(flags, sizeof(t_flags));
    while (++i < ac && (s = av[i]))
	{
		if (*s != '-' || ft_isdigit(*++s))
			return (ac - i);
        while (*s && ft_strchr("cfv", *s))
		{
			if (*s == 'c')
				flags->colored = 1;
			else if (*s == 'v')
				flags->debug = 1;
			else if (i < ac - 1)
				flags->filename = av[++i];
			else
				a_error("Error: file name missing\n");
			++s;
		}
		if (*s)
			flag_error(*s);
	}
	return (0);
}

static t_node	*pushback(t_node **cur, t_node *t)
{
	if (!t)
		return (NULL);
	if (*cur)
	{
		t->u = (*cur)->u;
		t->d = *cur;
		(*cur)->u->d = t;
		(*cur)->u = t;
	}
	else
		*cur = t;
	return (*cur);
}

static void		dup_search(t_node *t)
{
	t_node	*tmp;

	tmp = t;
	while (tmp != t->u)
	{
		if (tmp->num == t->u->num)
			error();
		tmp = tmp->d;
	}
}

t_node	*get_args(int argnum, char **av, int *n)
{
	long	num;
	t_node	*t;
	int		i;

	t = NULL;
	i = 0;
	*n = 0;
	while (i < argnum && ++*n)
	{
		num = ft_strtol(*(av + i), av + i, 10);
		if (((*av[i] && *av[i] != ' ') || num > INT_MAX || num < INT_MIN))
			error();
		if (!**(av + i))
			++i;
		if (!pushback(&t, new_node((int)num)))
			a_error("Error: memory allocation failed.\n");
		dup_search(t);
	}
	return (t);
}
