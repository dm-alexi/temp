#include "pushswap.h"

int 	count_size(t_list *t)
{
	int size;

	size = 0;
	while (t)
	{
		size += t->content_size;
		t = t->next;
	}
	return (size);
}

void	del_next(t_list *t)
{
	t_list	*tmp;

	if (t && (tmp = t->next))
	{
		t->next = tmp->next;
		free(tmp->content);
		free(tmp);
	}
}

void	remove_redundant_a(t_list *t, t_list *prev)
{
	t_list *tmp;

	tmp = t;
	if (ft_strequ(t->content, "ra"))
	{
		while (tmp->next)
		{
			if (!ft_strequ(tmp->next->content, "rb") && !ft_strequ(tmp->next->content, "rrb") && !ft_strequ(tmp->next->content, "sb") && !ft_strequ(tmp->next->content, "ra"))
				break ;
			tmp = tmp->next;
		}
		if (tmp->next && ft_strequ(tmp->next->content, "rra"))
		{
			del_next(tmp);
			del_next(prev);
		}
	}
	else if (ft_strequ(t->content, "rra"))
	{
		while (tmp->next)
		{
			if (!ft_strequ(tmp->next->content, "rb") && !ft_strequ(tmp->next->content, "rrb") && !ft_strequ(tmp->next->content, "sb") && !ft_strequ(tmp->next->content, "rra"))
				break ;
			tmp = tmp->next;
		}
		if (tmp->next && ft_strequ(tmp->next->content, "ra"))
		{
			del_next(tmp);
			del_next(prev);
		}
	}
}

void	remove_redundant_b(t_list *t, t_list *prev)
{
	t_list *tmp;

	tmp = t;
	if (ft_strequ(t->content, "rb"))
	{
		while (tmp->next)
		{
			if (!ft_strequ(tmp->next->content, "ra") && !ft_strequ(tmp->next->content, "rra") && !ft_strequ(tmp->next->content, "sa") && !ft_strequ(tmp->next->content, "rb"))
				break ;
			tmp = tmp->next;
		}
		if (tmp->next && ft_strequ(tmp->next->content, "rrb"))
		{
			del_next(tmp);
			del_next(prev);
		}
	}
	else if (ft_strequ(t->content, "rrb"))
	{
		while (tmp->next)
		{
			if (!ft_strequ(tmp->next->content, "ra") && !ft_strequ(tmp->next->content, "rra") && !ft_strequ(tmp->next->content, "sa") && !ft_strequ(tmp->next->content, "rrb"))
				break ;
			tmp = tmp->next;
		}
		if (tmp->next && ft_strequ(tmp->next->content, "rb"))
		{
			del_next(tmp);
			del_next(prev);
		}
	}
}

int	contract(t_list *t)
{
	int 	i;

	i = 0;
	while (t && t->next)
	{
		if ((ft_strequ(t->content, "ra") && ft_strequ(t->next->content, "rb")) || (ft_strequ(t->content, "rb") && ft_strequ(t->next->content, "ra")) ||
		(ft_strequ(t->content, "rra") && ft_strequ(t->next->content, "rrb")) || (ft_strequ(t->content, "rrb") && ft_strequ(t->next->content, "rra")))
		{
			del_next(t);
			ft_memcpy(t->content + t->content_size - 2, "r", 1);
			i = 1;
		}
		else if ((ft_strequ(t->content, "sa") && ft_strequ(t->next->content, "sb")) || (ft_strequ(t->content, "sb") && ft_strequ(t->next->content, "sa")))
		{
			del_next(t);
			ft_memcpy(t->content + t->content_size - 2, "s", 1);
			i = 1;
		}
		t = t->next;
	}
	return (i);
}

int	remove_dups(t_list *t)
{
	t_list	*tmp;
	int i = 0;

	while (t && (tmp = t->next) && tmp->next)
	{
		if ((ft_strequ(tmp->content, "pa") && (ft_strequ(tmp->next->content, "pb"))) ||
			(ft_strequ(tmp->content, "pb") && (ft_strequ(tmp->next->content, "pa"))))
		{
			del_next(t);
			del_next(t);
			i = 1;
		}
		else
			t = t->next;
	}
	return (i);
}

void	reduce(t_list *t)
{
	t_list	*tmp;

	tmp = t;
	while (tmp->next)
	{
		remove_redundant_a(tmp->next, tmp);
		if (tmp->next)
			remove_redundant_b(tmp->next, tmp);
		tmp = tmp->next;
	}
	tmp = t;
	while (tmp->next)
	{
		remove_redundant_a(tmp->next, tmp);
		if (tmp->next)
			remove_redundant_b(tmp->next, tmp);
		tmp = tmp->next;
	}
	tmp = t;
	while (tmp->next)
	{
		remove_redundant_a(tmp->next, tmp);
		if (tmp->next)
			remove_redundant_b(tmp->next, tmp);
		tmp = tmp->next;
	}
	while (contract(t));
	while (remove_dups(t));
}
