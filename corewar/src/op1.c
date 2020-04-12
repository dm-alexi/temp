/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:29:43 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/12 15:03:42 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	live(t_process *t, t_vm *vm, t_byte *argtypes, int *args)
{
	(void)argtypes;
	t->last_live = vm->cycle;
	++vm->live_calls;
	if (-args[0] > 0 && (unsigned)(-args[0]) <= vm->num_players)
	{
		vm->last_alive = vm->players[-args[0] - 1].num;
		if (vm->verbosity & LIVES)
			ft_printf("Player %u (%s) is said to be alive\n",
			-args[0], vm->players[-args[0] - 1].header.prog_name);
	}
}

void	ld(t_process *t, t_vm *vm, t_byte *argtypes, int *args)
{
	t->reg[args[1] - 1] = (argtypes[0] == DIR_CODE ? args[0] :
	read_dir(t->pc + args[0] % IDX_MOD, vm->arena));
	t->carry = !t->reg[args[1] - 1];
}

void	st(t_process *t, t_vm *vm, t_byte *argtypes, int *args)
{
	if (argtypes[1] == IND_CODE)
		write_bytes(t->reg[args[0] - 1], t->pc + args[1] % IDX_MOD, vm->arena);
	else
		t->reg[args[1] - 1] = t->reg[args[0] - 1];
}

void	add(t_process *t, t_vm *vm, t_byte *argtypes, int *args)
{
	(void)vm;
	(void)argtypes;
	t->reg[args[2] - 1] = t->reg[args[0] - 1] + t->reg[args[1] - 1];
	t->carry = !t->reg[args[2] - 1];
}

void	sub(t_process *t, t_vm *vm, t_byte *argtypes, int *args)
{
	(void)vm;
	(void)argtypes;
	t->reg[args[2] - 1] = t->reg[args[0] - 1] - t->reg[args[1] - 1];
	t->carry = !t->reg[args[2] - 1];
}
