/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:21:47 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/29 20:39:01 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_node		*new_node(t_col *column)
{
	t_node	*c;

	if ((c = (t_node*)malloc(sizeof(t_node))))
	{
		column->head.u->d = c;
		c->u = column->head.u;
		column->head.u = c;
		c->d = &(column->head);
		c->column = column;
	}
	return (c);
}

static t_node		*add_node(t_col *column, t_node *t)
{
	t_node	*c;

	if ((c = (t_node*)malloc(sizeof(t_node))))
	{
		column->head.u->d = c;
		c->u = column->head.u;
		column->head.u = c;
		c->d = &(column->head);
		c->column = column;
		c->l = t;
		t->r = c;
		column->size++;
	}
	return (c);
}

static void		clear_rows(int **arr)
{
    int		**tmp;

    tmp = arr;
    while (*tmp)
		free(*tmp++);
	free(arr);
}

t_node			*add_row(t_col *col_arr, int **rows)
{
	t_node	*start;
	t_node	*t;
	int		**r;
	int		i;

	r = rows;
	while (*r)
	{
		col_arr[(*r)[0]].size++;
		if (!(start = new_node(&(col_arr[(*r)[0]]))))
			exit(1);
		t = start;
		i = 0;
		while (++i < 5)
			if (!(t = add_node(&(col_arr[(*r)[i]]), t)))
				exit(1);
		start->l = t;
		t->r = start;
		++r;
	}
	clear_rows(rows);
	return (start);
}
