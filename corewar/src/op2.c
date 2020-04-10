/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:29:48 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/10 14:01:24 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	and(t_process *t, t_vm *vm, int *args)
{
	int		a;
	int		b;
	t_byte	c;

	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03)) == DIR_CODE)
		a = args[0];
	else if (c == IND_CODE)
		a = read_dir((t->pc + args[0] % IDX_MOD), vm->arena);
	else
		a = t->reg[args[0] - 1];
	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03)) == DIR_CODE)
		b = args[1];
	else if (c == IND_CODE)
		b = read_dir((t->pc + args[1] % IDX_MOD), vm->arena);
	else
		b = t->reg[args[1] - 1];
	t->reg[args[2] - 1] = a & b;
	t->carry = !t->reg[args[2] - 1];
}

void	or(t_process *t, t_vm *vm, int *args)
{
	int		a;
	int		b;
	t_byte	c;

	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03)) == DIR_CODE)
		a = args[0];
	else if (c == IND_CODE)
		a = read_dir((t->pc + args[0] % IDX_MOD), vm->arena);
	else
		a = t->reg[args[0] - 1];
	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03)) == DIR_CODE)
		b = args[1];
	else if (c == IND_CODE)
		b = read_dir((t->pc + args[1] % IDX_MOD), vm->arena);
	else
		b = t->reg[args[1] - 1];
	t->reg[args[2] - 1] = a | b;
	t->carry = !t->reg[args[2] - 1];
}

void	xor(t_process *t, t_vm *vm, int *args)
{
	int		a;
	int		b;
	t_byte	c;

	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03)) == DIR_CODE)
		a = args[0];
	else if (c == IND_CODE)
		a = read_dir((t->pc + args[0] % IDX_MOD), vm->arena);
	else
		a = t->reg[args[0] - 1];
	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03)) == DIR_CODE)
		b = args[1];
	else if (c == IND_CODE)
		b = read_dir((t->pc + args[1] % IDX_MOD), vm->arena);
	else
		b = t->reg[args[1] - 1];
	t->reg[args[2] - 1] = a ^ b;
	t->carry = !t->reg[args[2] - 1];
}

void	zjmp(t_process *t, t_vm *vm, int *args)
{
	(void)vm;
	t->pc = (t->pc + (t->carry ? args[0] % IDX_MOD :
	1 + g_tab[t->op].dirsize)) % MEM_SIZE;
}

void	ldi(t_process *t, t_vm *vm, int *args)
{
	int		a;
	int		b;
	t_byte	c;

	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03)) == DIR_CODE)
		a = args[0];
	else if (c == IND_CODE)
		a = read_dir((t->pc + args[0] % IDX_MOD), vm->arena);
	else
		a = t->reg[args[0] - 1];
	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03)) == DIR_CODE)
		b = args[1];
	else
		b = t->reg[args[1] - 1];
	t->reg[args[2] - 1] =
	read_dir((t->pc + (a + b) % IDX_MOD), vm->arena);
}
