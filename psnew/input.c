/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:41:18 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/14 21:56:45 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "pushswap.h"

int				get_flags(int ac, char **av, t_flags *flags)
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
				flags->verbose = 1;
			else if (i < ac - 1)
				flags->filename = av[++i];
			else
				a_error("Error: file name missing\n");
			++s;
		}
		if (*s || *(s - 1) == '-')
			flag_error(*s);
	}
	return (0);
}

static t_node	*pushback(t_node **cur, t_node *a)
{
	if (!a)
		return (NULL);
	if (*cur)
	{
		a->u = (*cur)->u;
		a->d = *cur;
		(*cur)->u->d = a;
		(*cur)->u = a;
	}
	else
		*cur = a;
	return (*cur);
}

static void		dup_search(t_node *a)
{
	t_node	*tmp;

	tmp = a;
	while (tmp != a->u)
	{
		if (tmp->num == a->u->num)
			error();
		tmp = tmp->d;
	}
}

t_node			*get_args(int argnum, char **av, int *n)
{
	long	num;
	t_node	*a;
	int		i;

	a = NULL;
	i = 0;
	*n = 0;
	while (i < argnum && ++*n)
	{
		num = ft_strtol(*(av + i), av + i, 10);
		if (num > INT_MAX || num < INT_MIN || (!num && *(av[i] - 1) != '0'))
			error();
		while (ft_isspace(*av[i]))
			++av[i];
		if (*av[i] && !(ft_isdigit(*av[i]) || *av[i] == '-' || *av[i] == '+'))
			error();
		if (!*(av[i]))
			++i;
		if (!pushback(&a, new_node((int)num)))
			mem_error();
		dup_search(a);
	}
	return (a);
}
