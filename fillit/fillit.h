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

typedef struct	s_node
{
	struct s_node	*u;
	struct s_node	*d;
	struct s_node	*l;
	struct s_node	*r;
	struct s_col	*col;
}				node;

typedef struct	s_col
{
	int		size;
	struct s_node	head;
	struct s_col	*l;
	struct s_col	*r;
}				column;

#endif
