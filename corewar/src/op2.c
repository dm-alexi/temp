#include "corewar.h"

void	and(t_process *t, t_vm *vm, int *args)
{
	int		a;
	int		b;
	t_byte	c;

	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03)) == T_DIR)
		a = args[0];
	else if (c == T_IND)
		a = read_dir((t->pc + args[0] % IDX_MOD) % MEM_SIZE, vm->arena);
	else if (c == T_REG)
		a = t->reg[args[0] - 1];
	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03)) == T_DIR)
		b = args[1];
	else if (c == T_IND)
		b = read_dir((t->pc + args[1] % IDX_MOD) % MEM_SIZE, vm->arena);
	else if (c == T_REG)
		b = t->reg[args[1] - 1];
	t->reg[args[2] - 1] = a & b;
}

void	or(t_process *t, t_vm *vm, int *args)
{
	int		a;
	int		b;
	t_byte	c;

	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03)) == T_DIR)
		a = args[0];
	else if (c == T_IND)
		a = read_dir((t->pc + args[0] % IDX_MOD) % MEM_SIZE, vm->arena);
	else if (c == T_REG)
		a = t->reg[args[0] - 1];
	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03)) == T_DIR)
		b = args[1];
	else if (c == T_IND)
		b = read_dir((t->pc + args[1] % IDX_MOD) % MEM_SIZE, vm->arena);
	else if (c == T_REG)
		b = t->reg[args[1] - 1];
	t->reg[args[2] - 1] = a | b;
}

void	xor(t_process *t, t_vm *vm, int *args)
{
	int		a;
	int		b;
	t_byte	c;

	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03)) == T_DIR)
		a = args[0];
	else if (c == T_IND)
		a = read_dir((t->pc + args[0] % IDX_MOD) % MEM_SIZE, vm->arena);
	else if (c == T_REG)
		a = t->reg[args[0] - 1];
	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03)) == T_DIR)
		b = args[1];
	else if (c == T_IND)
		b = read_dir((t->pc + args[1] % IDX_MOD) % MEM_SIZE, vm->arena);
	else if (c == T_REG)
		b = t->reg[args[1] - 1];
	t->reg[args[2] - 1] = a ^ b;
}

void	zjmp(t_process *t, t_vm *vm, int *args)
{
	t->pc = (t->pc + (t->carry ? args[0] % IDX_MOD :
	1 + g_tab[t->op].dirsize)) % MEM_SIZE;
}

void	ldi(t_process *t, t_vm *vm, int *args)
{
	int		a;
	int		b;
	t_byte	c;

	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03)) == T_DIR)
		a = args[0];
	else if (c == T_IND)
		a = read_dir((t->pc + args[0] % IDX_MOD) % MEM_SIZE, vm->arena);
	else if (c == T_REG)
		a = t->reg[args[0] - 1];
	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03)) == T_DIR)
		b = args[1];
	else if (c == T_REG)
		b = t->reg[args[1] - 1];
	t->reg[args[2] - 1] =
	read_dir((t->pc + (a + b) % IDX_MOD) % MEM_SIZE, vm->arena);
}
