/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:21:47 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/25 19:21:51 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static node		*new_node(col *column)
{
	node	*c;

	if ((c = (node*)malloc(sizeof(node))))
	{
		column->head.u->d = c;
		c->u = column->head.u;
		column->head.u = c;
		c->d = &(column->head);
		c->column = column;
	}
	return (c);
}

static node		*add_node(col *column, node *t)
{
	node	*c;

	if ((c = (node*)malloc(sizeof(node))))
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

node			*add_row(col *col_arr, int **rows)
{
	node	*start;
	node	*t;
	int		**r;

	r = rows;
	while (*r)
	{
		col_arr[(*r)[0]].size++;
		if (!(start = new_node(&(col_arr[(*r)[0]]))))
			exit(1);
		t = start;
		for (int i = 1; i < 5; ++i)
			if (!(t = add_node(&(col_arr[(*r)[i]]), t)))
				exit(1);
		start->l = t;
		t->r = start;
		++r;
	}
	return (start);
}
