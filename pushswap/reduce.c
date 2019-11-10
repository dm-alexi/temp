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

void	contract(t_list *t)
{
	while (t && t->next)
	{
		if ((ft_strequ(t->content, "ra") && ft_strequ(t->next->content, "rb")) || (ft_strequ(t->content, "rb") && ft_strequ(t->next->content, "ra")) ||
		(ft_strequ(t->content, "rra") && ft_strequ(t->next->content, "rrb")) || (ft_strequ(t->content, "rrb") && ft_strequ(t->next->content, "rra")))
		{
			del_next(t);
			ft_memcpy(t->content + t->content_size - 2, "r", 1);
		}
		else if ((ft_strequ(t->content, "sa") && ft_strequ(t->next->content, "sb")) || (ft_strequ(t->content, "sb") && ft_strequ(t->next->content, "sa")))
		{
			del_next(t);
			ft_memcpy(t->content + t->content_size - 2, "s", 1);
		}
		t = t->next;
	}
}

void	reduce(t_list *t)
{
	t_list	*tmp;
	//char	*s;

	//if (!(s = (char *)malloc(count_size(t) + 1)))
	//	a_error("Error: memory allocation failed.\n");
	tmp = t;
	while (tmp->next)
	{
		remove_redundant_a(tmp->next, tmp);
		if (tmp->next)
			remove_redundant_b(tmp->next, tmp);
		tmp = tmp->next;
	}
	contract(t);
}