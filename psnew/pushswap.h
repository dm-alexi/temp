/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:10:28 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/13 22:56:21 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"

enum			e_command
{
	SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
};

typedef struct	s_flags
{
	char	*filename;
	char	verbose;
	char	colored;
}				t_flags;

typedef struct	s_node
{
	int				num;
	struct s_node	*u;
	struct s_node	*d;
}				t_node;

typedef struct	s_com
{
	enum e_command	com;
	struct s_com	*next;
}				t_com;

typedef struct	s_stack
{
	t_node	*a;
	t_node	*b;
	int		a_count;
	int		b_count;
	t_com	*start;
	t_com	*fin;
}				t_stack;

void			error(void);
void			a_error(const char *s);
void			flag_error(char c);
void			file_error(const char *s);
void			mem_error(void);

t_node			*get_args(int argnum, char **av, int *n);
int				get_flags(int ac, char **av, t_flags *flags);
int				get_com(int fd, t_stack *t, t_flags *flags);

t_node			*new_node(int n);
t_node			*add(t_node **cur, t_node *t);
t_node			*pop(t_node **cur);
void			swap(t_node *t);
void			exec(t_stack *t, enum e_command com);

int				sorted(t_node *a);
int				rsorted(t_node *a, int rev);
void			rsort(t_stack *t);
void			sort(t_stack *t);
void			sort_3(t_stack *t);
void			mainsort(t_stack *t);
int				find_closest(t_stack *t, int rev);
void			roll(t_stack *t, int a, int b);

void			show_stacks(t_stack *t, t_flags *flags, enum e_command com);
void			print_result(t_stack *t, int fd);

void			clear_stacks(t_stack *t);

#endif
