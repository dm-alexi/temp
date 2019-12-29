/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:04 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/29 17:28:26 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"
# define NODE 1
# define EDGE 2

typedef enum	e_command
{
	UNKNOWN, START, END
}				t_command;

typedef struct	s_node
{
	char			*name;
	struct s_edge	*nodes;
	int				x;
	int				y;
	int				distance;
}				t_node;

typedef struct	s_edge
{
	t_node			*node;
	struct s_edge	*next;
}				t_edge;

typedef struct	s_graph
{
	int		ant_num;
	int		node_num;
	t_node	**nodes;
	t_node	*start;
	t_node	*finish;
}				t_graph;

void			sys_error(void);
void			error(void);

void			print_graph(t_graph *graph);
void 			print_node(const t_node *a);

t_graph			*get_graph(void);
int				get_line(char **line, t_command *com);
void			get_nodes(t_graph *graph, char **line);
void			get_edges(t_graph *graph, char **line);
void			delete_graph(t_graph *graph);

#endif
