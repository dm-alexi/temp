#include "pushswap.h"

int		adjust_count_ab(t_stack *t, int n)
{
    int		i;
    int		j;
    int		m1;
    int		m2;
    t_node	*tmp;

    i = 0;
    j = 0;
    tmp = t->a;
    while (tmp->num != n && ++i)
		tmp = tmp->d;
	if (t->b_count <= 1)
		return (i <= t->a_count / 2 ? i : t->a_count - i);
	tmp = t->b;
	while (!(tmp->num < n && tmp->u->num > n) &&
	!(tmp->num > tmp->u->num && (n < tmp->u->num || n > tmp->num)) && ++j)
		tmp = tmp->d;
	m1 = i > j ? i : j;
	m2 = t->a_count - i > t->b_count - j ? t->a_count - i : t->b_count - j;
	m1 = m1 < i + t->b_count - j ? m1 : i + t->b_count - j;
	m2 = m2 < j + t->a_count - i ? m2 : j + t->a_count - i;
	return (m1 < m2 ? m1 : m2);
}

int		adjust_count_ba(t_stack *t, int n)
{
    int		i;
    int		j;
    int		m1;
    int		m2;
    t_node	*tmp;

    i = 0;
    j = 0;
    tmp = t->b;
    while (tmp->num != n && ++j)
		tmp = tmp->d;
	if (t->a_count <= 1)
		return (i <= t->b_count / 2 ? j : t->b_count - j);
	tmp = t->a;
	while (!(tmp->num > n && tmp->u->num < n) &&
	!(tmp->num < tmp->u->num && (n > tmp->u->num || n < tmp->num)) && ++i)
		tmp = tmp->d;
	m1 = i > j ? i : j;
	m2 = t->a_count - i > t->b_count - j ? t->a_count - i : t->b_count - j;
	m1 = m1 < i + t->b_count - j ? m1 : i + t->b_count - j;
	m2 = m2 < j + t->a_count - i ? m2 : j + t->a_count - i;
	return (m1 < m2 ? m1 : m2);
}

void roll(t_stack *t, int a, int b)
{
	if (a > 0 && b > 0)
		while (a && b && a-- && b--)
			exec(t, "rr");
	else if (a < 0 && b < 0)
		while (a && b && a++ && b++)
			exec(t, "rrr");
	if (a > 0)
		while (a--)
			exec(t, "ra");
	else
		while (a++)
			exec(t, "rra");
	if (b > 0)
		while (b--)
			exec(t, "rb");
	else
		while (b++)
			exec(t, "rrb");
}

void	adjust_ab(t_stack *t, int n)
{
	int		i;
    int		j;
    int		m1;
    int		m2;
    t_node	*tmp;

    i = 0;
    j = 0;
    tmp = t->a;
    while (tmp->num != n && ++i)
		tmp = tmp->d;
	if (t->b_count > 1 && (tmp = t->b))
		while (!(tmp->num < n && tmp->u->num > n) &&
		!(tmp->num > tmp->u->num && (n < tmp->u->num || n > tmp->num)) && ++j)
			tmp = tmp->d;
	m1 = i > j ? i : j;
	m2 = t->a_count - i > t->b_count - j ? t->a_count - i : t->b_count - j;
	if (m1 <= m2 && m1 <= i + t->b_count - j && m1 <= j + t->a_count - i)
		roll(t, i, j);
	else if (m2 <= m1 && m2 <= i + t->b_count - j && m2 <= j + t->a_count - i)
		roll(t, -(t->a_count - i), -(t->b_count - j));
	else if (i + t->b_count - j <= j + t->a_count - i)
		roll(t, i, -(t->b_count - j));
	else
		roll(t, -(t->a_count - i), j);
}

void	adjust_ba(t_stack *t, int n)
{
	int		i;
    int		j;
    int		m1;
    int		m2;
    t_node	*tmp;

    i = 0;
    j = 0;
    tmp = t->b;
    while (tmp->num != n && ++j)
		tmp = tmp->d;
	if (t->a_count > 1 && (tmp = t->a))
		while (!(tmp->num > n && tmp->u->num < n) &&
		!(tmp->num < tmp->u->num && (n > tmp->u->num || n < tmp->num)) && ++i)
			tmp = tmp->d;
	m1 = i > j ? i : j;
	m2 = t->a_count - i > t->b_count - j ? t->a_count - i : t->b_count - j;
	if (m1 <= m2 && m1 <= i + t->b_count - j && m1 <= j + t->a_count - i)
		roll(t, i, j);
	else if (m2 <= m1 && m2 <= i + t->b_count - j && m2 <= j + t->a_count - i)
		roll(t, -(t->a_count - i), -(t->b_count - j));
	else if (i + t->b_count - j <= j + t->a_count - i)
		roll(t, i, -(t->b_count - j));
	else
		roll(t, -(t->a_count - i), j);
}

int find_closest_ab(t_stack *t)
{
	int		moves;
	int		num;
	int		d;
	t_node	*tmp;

	num = t->a->num;
	moves = adjust_count_ab(t, num);
	tmp = t->a->d;
	while (tmp != t->a)
	{
		if ((d = adjust_count_ab(t, tmp->num)) < moves)
		{
			moves = d;
			num = tmp->num;
		}
		tmp = tmp->d;
	}
	return (num);
}

int find_closest_ba(t_stack *t)
{
	int		moves;
	int		num;
	int		d;
	t_node	*tmp;

	num = t->b->num;
	moves = adjust_count_ba(t, num);
	tmp = t->b->d;
	while (tmp != t->b)
	{
		if ((d = adjust_count_ba(t, tmp->num)) < moves)
		{
			moves = d;
			num = tmp->num;
		}
		tmp = tmp->d;
	}
	return (num);
}

void	dsort(t_stack *t)
{
    while (!rsorted(t->a, 0) && t->a_count > 3)
	{
		adjust_ab(t, find_closest_ab(t));
		exec(t, "pb");
	};
	if (!rsorted(t->a, 0))
		sort_3(t);
	while (t->b_count)
	{
		adjust_ba(t, find_closest_ba(t));
		exec(t, "pa");
	}
	if (!sorted(t->a))
		rsort(t);
}
