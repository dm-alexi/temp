#include "corewar.h"

void	sti(t_process *t, t_vm *vm, int *args)
{

}

void	fork(t_process *t, t_vm *vm, int *args)
{

}

void	lld(t_process *t, t_vm *vm, int *args)
{
	t->reg[args[1] - 1] =
	(((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03) == T_DIR ? args[0] :
	read_dir((t->pc + args[0]) % MEM_SIZE, vm->arena)); // check original corewar if it reads 2 of 4 bytes
	t->carry = !t->reg[args[1] - 1];
}

void	lldi(t_process *t, t_vm *vm, int *args)
{

}

void	lfork(t_process *t, t_vm *vm, int *args)
{

}
