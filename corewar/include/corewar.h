#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"

typedef unsigned char t_byte;

typedef struct	s_player
{
	t_header	header;
	t_byte		*code;
	unsigned	num;
}				t_player;

typedef struct	s_process
{
    unsigned int		num;
    unsigned int		last_live;
    int					carry;
    int					op;
    int					pc;
    t_byte				reg[REG_NUMBER][REG_SIZE];
    struct s_process	*next;
    unsigned			player_num;
}				t_process;

typedef struct	s_vm
{
	unsigned	num_players;
	t_player	*players;
	unsigned	dump_cycle;
	unsigned	dump_len;
	t_byte		arena[MEM_SIZE];
	unsigned	num_process;
	t_process	*start;
}				t_vm;

void			sys_error(char *s);
void			error(char *s);
void			error_ext(char *s, char *t);

void			input(t_vm *vm, int ac, char **av);
void			get_players(t_vm *vm, char **files);
void			introduce(t_vm *vm);
void			init_arena(t_vm *vm);
t_process		*new_process(t_process *next, unsigned num, unsigned player_num);
void			delete_vm(t_vm *vm);
#endif
