#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"

typedef struct	s_player
{
	char	*name;
}				t_player;

typedef struct	s_vm
{
	int		num_players;
	char	**players;
	long	dump_cycle;
	int		dump_len;
}				t_vm;

void			sys_error(void);
void			error(char *s);
void			error_ext(char *s, char *t);

void			input(t_vm *vm, int ac, char **av);
void			get_players(t_vm *vm, char **files);

#endif
