#ifndef LEMIN_H_INCLUDED
# define LEMIN_H_INCLUDED
# include "libft/libft.h"

typedef enum	e_command
{
	UNKNOWN, START, END
}				t_command;

typedef struct	s_node
{
	char			*name;
	struct s_node	*nodes;
	int				distance;
	int				x;
	int				y;
}				t_node;

typedef struct	s_edge
{
	t_node	*node1;
	t_node	*node2;
}				t_edge;

typedef struct	s_graph
{
	int		ant_num;
	int		node_num;
	t_node	**nodes;
	t_edge	*edges;
	t_node	*start;
	t_node	*finish;
}				t_graph;

void			sys_error(void);
void			error(void);

void			print_graph(t_graph *graph);
void	include_nodes(t_graph *graph, t_list *lst);
t_graph			*get_graph(void);
t_list			*new_node(char *line, t_command com);
#endif
