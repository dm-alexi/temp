#include "corewar.h"

void	and(t_process *t, t_vm *vm)
{

}

void	or(t_process *t, t_vm *vm)
{

}

void	xor(t_process *t, t_vm *vm)
{

}

void	zjmp(t_process *t, t_vm *vm)
{
	t->pc = (t->pc + (t->carry ? read_ind(t->pc + 1, vm->arena) % IDX_MOD :
	1 + DIR_SIZE)) % MEM_SIZE;
}

void	ldi(t_process *t, t_vm *vm)
{

}
