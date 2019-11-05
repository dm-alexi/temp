#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"

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
int				rsorted(t_node *a, int rev);
t_list			*sort(t_node **a, t_node **b, int n);
t_list			*merge_sort(t_node **a, t_node **b, int n);
void			print_list(int fd, t_list *t);
void			add_prev(t_list **last, char *s, size_t t);
char			*exec(t_node **a, t_node **b, char *s);


void	show_stack(t_node *a);
#endif
