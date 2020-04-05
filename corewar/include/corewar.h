/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:28:58 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/05 16:39:10 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# define OP 16

typedef unsigned char t_byte;

typedef struct	s_player
{
	t_header	header;
	t_byte		*code;
	unsigned	num;
}				t_player;

typedef struct	s_process
{
    unsigned			num; //check if this is necessary
    unsigned			last_live;
    t_byte				carry;
    t_byte				op;
    int					pc;
    //t_byte				reg[REG_NUMBER][REG_SIZE];
    int					reg[REG_NUMBER];
    struct s_process	*next;
    unsigned			player_num;
    unsigned			exec_cycle;
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
	unsigned	cycle;
	unsigned	cycles_to_die;
	unsigned	checks;
	unsigned	next_check;
	unsigned	live_calls;
	unsigned	last_alive;
}				t_vm;

typedef struct	s_op
{
	void	(*func)(t_process*, t_vm*, int* args);
	t_byte	argtype;
	int		argnum;
	char	args[3];
	int		dirsize;
	int		lag;
}				t_op;

extern const t_op	g_tab[];

void			sys_error(char *s);
void			error(char *s);
void			error_ext(char *s, char *t);

void			input(t_vm *vm, int ac, char **av);
void			get_players(t_vm *vm, char **files);

void			introduce(t_vm *vm);
void			declare_alive(t_vm *vm, unsigned player_num);
void			declare_winner(t_vm *vm);
void			dump(t_vm *vm);

void			init_arena(t_vm *vm);
int				read_dir(int start, t_byte *arena);
int				read_ind(int start, t_byte *arena);
void			write_bytes(int n, int start, t_byte *arena);
t_process		*new_process(t_process *next, unsigned num, unsigned player_num,
					t_byte pc);
int				battle(t_vm *vm);
void			read_instr(t_process *cur, t_vm *vm);
void			exec_instr(t_process *cur, t_vm *vm);
void			delete_vm(t_vm *vm);

void			live(t_process *t, t_vm *vm, int *args);
void			ld(t_process *t, t_vm *vm, int *args);
void			st(t_process *t, t_vm *vm, int *args);
void			add(t_process *t, t_vm *vm, int *args);
void			sub(t_process *t, t_vm *vm, int *args);
void			and(t_process *t, t_vm *vm, int *args);
void			or(t_process *t, t_vm *vm, int *args);
void			xor(t_process *t, t_vm *vm, int *args);
void			zjmp(t_process *t, t_vm *vm, int *args);
void			ldi(t_process *t, t_vm *vm, int *args);
void			sti(t_process *t, t_vm *vm, int *args);
void			ffork(t_process *t, t_vm *vm, int *args);
void			lld(t_process *t, t_vm *vm, int *args);
void			lldi(t_process *t, t_vm *vm, int *args);
void			lfork(t_process *t, t_vm *vm, int *args);
void			aff(t_process *t, t_vm *vm, int *args);

#endif
