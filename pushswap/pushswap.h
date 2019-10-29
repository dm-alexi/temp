#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct	s_flags
{
	char	*filename;
	char	debug : 1;
	char	colored : 1;
}				t_flags;

int				error(void);
int				inc_flag(char c);
int				get_flags(int ac, char **av, t_flags *flags);

#endif
