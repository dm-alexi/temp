/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:11:50 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/30 23:08:40 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct	s_node
{
	struct s_node	*u;
	struct s_node	*d;
	struct s_node	*l;
	struct s_node	*r;
	struct s_col	*column;
}				t_node;

typedef struct	s_col
{
	int				size;
	struct s_col	*prev;
	struct s_col	*next;
	struct s_node	head;
	int				order;
}				t_col;

int				**get_rows(int ord, int num, int type, int sq);
t_node			*add_row(t_col *col_arr, int **row);
t_node			**solve(t_col *arr, int n);
void			print_result(t_node **res, int n, int sq);
int				*get_figures(char *s, int *n);
void			del_columns(t_col *arr, int n);
t_col			*make_matrix(int *figures, int n, int sq);

#endif
