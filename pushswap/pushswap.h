#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct	s_flags
{
	char	*filename;
	char	debug : 1;
	char	colored : 1;
}				t_flags;

void			error(void);
void			a_error(const char *s);
void			flag_error(char c);
int				*get_args(int n, char **av);
int				get_flags(int ac, char **av, t_flags *flags);

#endif
