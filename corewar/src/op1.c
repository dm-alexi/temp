#include "corewar.h"

void	live(t_process *t, t_vm *vm)
{
    int	n;

	t->last_live = vm->cycle;
    ++vm->live_calls;
	n = readbytes(t->pc + 1, vm->arena);
	if (-n > 0 && -n <= vm->num_players)
		vm->last_alive = vm->players[-n - 1].num;
	t->pc = (t->pc + 1 + DIR_SIZE) % MEM_SIZE;
}

void	ld(t_process *t, t_vm *vm)
{

}

void	st(t_process *t, t_vm *vm)
{

}

void	add(t_process *t, t_vm *vm)
{

}

void	sub(t_process *t, t_vm *vm)
{

}
