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
void			file_error(const char *s);
t_node			*get_args(int argnum, char **av, int *n);
int				get_flags(int ac, char **av, t_flags *flags);
t_node			*new_node(int n);
t_node			*add(t_node **cur, t_node *t);
t_node			*pop(t_node **cur);
void			swap(t_node *t);
int				get_com(int fd, t_node **a, t_node **b);
void			clear_lists(t_node *a, t_node *b);
int				sorted(t_node *a);
int			rsorted(t_node *a, int rev);
char	*sort(t_node **a, t_node **b, int n);

#endif
