#include "corewar.h"

void	live(t_process *t, t_vm *vm, int *args)
{
	t->last_live = vm->cycle;
    ++vm->live_calls;
	if (-args[0] > 0 && -args[0] <= vm->num_players) //check if it's really negative
		vm->last_alive = vm->players[-args[0] - 1].num;
}

void	ld(t_process *t, t_vm *vm, int *args)
{
	t->reg[args[1] - 1] =
	(((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03) == T_DIR ? args[0] :
	read_dir((t->pc + args[0] % IDX_MOD) % MEM_SIZE, vm->arena));
	t->carry = !t->reg[args[1] - 1];
}

void	st(t_process *t, t_vm *vm, int *args)
{
	if (((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03) == T_IND)
		write_bytes(t->reg[args[0] - 1],
		(t->pc + args[1] % IDX_MOD) % MEM_SIZE, vm->arena);
	else
		t->reg[args[1] - 1] = t->reg[args[0] - 1];
}

void	add(t_process *t, t_vm *vm, int *args)
{
	t->reg[args[2] - 1] = t->reg[args[0] - 1] + t->reg[args[1] - 1];
    t->carry = !t->reg[args[2] - 1];
}

void	sub(t_process *t, t_vm *vm, int *args)
{
	t->reg[args[2] - 1] = t->reg[args[0] - 1] - t->reg[args[1] - 1];
    t->carry = !t->reg[args[2] - 1];
}
