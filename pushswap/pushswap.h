#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct	s_flags
{
	char	*filename;
	char	debug;
	char	colored;
}				t_flags;

typedef struct	s_node
{
	int				num;
	struct s_node	*u;
	struct s_node	*d;
}				t_node;

void			error(void);
void			a_error(const char *s);
void			flag_error(char c);
t_node			*get_args(int n, char **av);
int				get_flags(int ac, char **av, t_flags *flags);
t_node			*push(t_node **cur, int n);

#endif
