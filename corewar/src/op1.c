/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:29:43 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/09 18:22:19 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_process *t, t_vm *vm, int *args)
{
	t->last_live = vm->cycle;
	++vm->live_calls;
	//check if it's really negative
	if (-args[0] > 0 && (unsigned)(-args[0]) <= vm->num_players)
		vm->last_alive = vm->players[-args[0] - 1].num;
}

void	ld(t_process *t, t_vm *vm, int *args)
{
	t->reg[args[1] - 1] =
	(((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03) == DIR_CODE ? args[0] :
	read_dir((t->pc + args[0] % IDX_MOD), vm->arena));
	t->carry = !t->reg[args[1] - 1];
}

void	st(t_process *t, t_vm *vm, int *args)
{
	if (((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03) == IND_CODE)
		write_bytes(t->reg[args[0] - 1],
		(t->pc + args[1] % IDX_MOD) % MEM_SIZE, vm->arena);
	else
		t->reg[args[1] - 1] = t->reg[args[0] - 1];
}

void	add(t_process *t, t_vm *vm, int *args)
{
	(void)vm;
	t->reg[args[2] - 1] = t->reg[args[0] - 1] + t->reg[args[1] - 1];
	t->carry = !t->reg[args[2] - 1];
}

void	sub(t_process *t, t_vm *vm, int *args)
{
	(void)vm;
	t->reg[args[2] - 1] = t->reg[args[0] - 1] - t->reg[args[1] - 1];
	t->carry = !t->reg[args[2] - 1];
}
