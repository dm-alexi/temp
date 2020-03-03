/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:04 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/28 18:46:11 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"
# define NODE 1
# define EDGE 2

typedef enum	e_type
{
	UNKNOWN, START, FINISH
}				t_type;

typedef struct	s_node
{
	char			*name;
	struct s_edge	*edges;
	struct s_node	*prev;
	int				x;
	int				y;
	int				rank;
	int				distance;
	t_type			type;
}				t_node;

typedef struct	s_edge
{
	t_node			*node;
	int				len;
	struct s_edge	*next;
}				t_edge;

typedef struct	s_graph
{
	int		ant_num;
	int		node_num;
	int		path_num;
	int		path_max;
	int		moves;
	int		*ants;
	int		*path_len;
	t_node	**nodes;
	t_edge	**paths;
	t_edge	**backup;
	t_node	*start;
	t_node	*finish;
}				t_graph;

typedef struct	s_queue
{
	t_node			*node;
	struct s_queue	*next;
}				t_queue;

void			sys_error(void);
void			error(void);

void			print_graph(t_graph *graph);
void			print_node(const t_node *a);
void			print_path(t_edge *path);

t_graph			*get_graph(void);
int				get_line(char **line, t_type *type);
void			get_nodes(t_graph *graph, char **line);
void			get_edges(t_graph *graph, char **line);
void			delete_graph(t_graph *graph);
void			delete_path(t_edge *path);
void			delete_paths(t_edge **paths, int n);
void			bfs(t_graph *graph);
void			belford(t_graph *graph);
t_edge			*find(t_node *node, t_edge *edge);
t_edge			*get_path(t_graph *graph);
void			set_rank(t_edge *path, int rank);
void			set_ranks(t_edge **paths, int n);
void			reset_ranks(t_graph *graph);
int				path_len(t_edge *path);
int				count_moves(t_edge **paths, int n_paths, int ants);
void			reverse_paths(t_graph *graph);
void			restore_paths(t_graph *graph);
void			reset_distance(t_graph *graph);
void			solve(t_graph *graph);
void			distribute(t_graph *graph);
void			split_paths(t_graph *graph);
void			restore_graph(t_graph *graph);
void			remove_edge(t_node *node, t_edge **edge);

#endif
