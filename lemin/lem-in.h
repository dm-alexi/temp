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
	struct s_edge	*edges;
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
	int		antnum;
	t_node	*nodes;
	t_edge	*edges;
	t_node	*start;
	t_node	*finish;
}				t_graph;

void			sys_error(void);
void			error(void);
#endif
