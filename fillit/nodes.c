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
		c->l = c;
		c->r = c;
	}
	return (c);
}

static node		*add_node(col *column, node *start)
{
	node	*c;

	if ((c = (node*)malloc(sizeof(node))))
	{
		column->head.u->d = c;
		c->u = column->head.u;
		column->head.u = c;
		c->d = &(column->head);
		c->column = column;
		c->l = start->l;
		c->r = start;
		start->l->r = c;
		start->l = c;
		column->size++;
	}
	return (c);
}

//calls for optimization
node			*add_row(col *col_arr, int **rows)
{
	node	*start;
	int		**r;

	r = rows;
	while (*r)
	{
		col_arr[(*r)[0]].size++;
		if (!(start = new_node(&(col_arr[(*r)[0]]))))
			exit(1);
		for (int i = 1; i < 5; ++i)
			if (!(add_node(&(col_arr[(*r)[i]]), start)))
				exit(1);
		++r;
	}
	return (start);
}
