#include "corewar.h"

void	and(t_process *t, t_vm *vm, int *args)
{

}

void	or(t_process *t, t_vm *vm, int *args)
{

}

void	xor(t_process *t, t_vm *vm, int *args)
{

}

void	zjmp(t_process *t, t_vm *vm, int *args)
{
	t->pc = (t->pc + (t->carry ? args[0] % IDX_MOD :
	1 + g_tab[t->op].dirsize)) % MEM_SIZE;
}

void	ldi(t_process *t, t_vm *vm, int *args)
{

}
