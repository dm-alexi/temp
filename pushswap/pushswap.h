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

typedef struct	s_stack
{
	t_node	*a;
	t_node	*b;
	int		a_count;
	int		b_count;
	t_list	*start;
	t_list	*fin;
}               t_stack;

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
int				get_com(int fd, t_stack *t);
void	clear_stacks(t_stack *t);
int				sorted(t_node *a);
int				rsorted(t_node *a, int rev);
void rsort(t_stack *t);
void	sort(t_stack *t);
void	sort_3(t_stack *t);
void merge_sort(t_stack *t);
void roll_a(t_stack *t, int steps);
void roll_b(t_stack *t, int steps);
void			print_list(int fd, t_list *t);
void			add_prev(t_list **last, char *s, size_t t);
void	exec(t_stack *t, char *s);

void	show_stacks(t_stack *t);
void	print_log(t_stack *t);

void	reduce(t_list *t);
void	isort_a(t_stack *t, int n);
void	isort_b(t_stack *t, int n);
#endif
