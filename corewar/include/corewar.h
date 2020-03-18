#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"

typedef struct	s_player
{
	t_header	header;
	char		*code;
	int			num;
}				t_player;

typedef struct	s_vm
{
	int			num_players;
	t_player	*players;
	long		dump_cycle;
	int			dump_len;
	char		arena[MEM_SIZE];
}				t_vm;

void			sys_error(void);
void			sys_error_ext(char *s);
void			error(char *s);
void			error_ext(char *s, char *t);

void			input(t_vm *vm, int ac, char **av);
void			get_players(t_vm *vm, char **files);
void			introduce(t_vm *vm);
#endif
