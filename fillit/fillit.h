/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:11:50 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/15 18:34:39 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>

typedef struct	s_node
{
	struct s_node	*u;
	struct s_node	*d;
	struct s_node	*l;
	struct s_node	*r;
	struct s_col	*column;
}				node;

typedef struct	s_col
{
	int				size;
	struct s_col	*prev;
	struct s_col	*next;
	struct s_node	head;
	char			name[5];
}				col;

col		*make_columns(int n, int sq);
int		**get_rows(int ord, int num, int type, int sq);
node	*new_node(col *column);
node	*add_node(col *column, node *start);
node	*add_row(col *col_arr, int **row);
int		**clear_rows(int **arr);
node	**solve(col *arr, int n);

#endif
