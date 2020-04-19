/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:50:40 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/20 01:44:25 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_option(char c, t_param *param)
{
	if (c == 'a' || c == 'A')
		param->all = (c == 'A' ? ALMOST_ALL : ALL);
	else if (c == 'd')
		param->directory = 1;
	else if (c == 'f')
	{
		param->longlist = 0;
		param->all = ALL;
		param->sort = NO_SORT;
	}
	else if (c == 'g')
	{}
	else if (c == 'h')
		param->human = HUMAN;
	else if (c == 'l')
		param->longlist = 1;
	else if (c == 'o')
	{}
	else if (c == 'r')
		param->reverse = 1;
	else if (c == 'R')
		param->recursive = 1;
	else if (c == 't')
		param->sort = SORT_MOD_TIME;
	else if (c == 'U')
		param->sort = NO_SORT;
	else
		error3("invalid option -", c);
}

static void	add_option_long(char *s, t_param *param)
{
	if (ft_strequ(s, "--all"))
		add_option('a', param);
	else if (ft_strequ(s, "--almost-all"))
		add_option('A', param);
	else if (ft_strequ(s, "--directory"))
		add_option('d', param);
	else if (ft_strequ(s, "--human-readable"))
		add_option('h', param);
	else if (ft_strequ(s, "--si"))
		param->human = HUMAN_SI;
	else if (ft_strequ(s, "--reverse"))
		add_option('r', param);
	else if (ft_strequ(s, "--recursive"))
		add_option('R', param);
	else
		error2("invalid option ", s);
}

static void	add_option_short(char *s, t_param *param)
{
	while (*++s)
		add_option(*s, param);
}

t_list		*input(int ac, char **av, t_param *param)
{
	t_list	*start;
	t_list	*t;
	int		i;

	start = NULL;
	i = 0;
	while (++i < ac)
		if (ft_strnequ(av[i], "--", 2))
			add_option_long(av[i], param);
		else if (*av[i] == '-')
			add_option_short(av[i], param);
	while (--i > 0)
		if (*av[i] != '-')
		{
			if (!(t = ft_lstnew(av[i], ft_strlen(av[i]) + 1)))
				sys_error(NULL);
			ft_lstadd(&start, t);
		}
	if (!start)
		start = ft_lstnew(".", 2);
	return (start);
}
