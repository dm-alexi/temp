/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:29:53 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/10 14:00:08 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	sti(t_process *t, t_vm *vm, int *args)
{
	int		a;
	int		b;
	t_byte	c;

	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03)) == DIR_CODE)
		a = args[1];
	else if (c == IND_CODE)
		a = read_dir((t->pc + args[1] % IDX_MOD), vm->arena);
	else
		a = t->reg[args[1] - 1];
	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 2) & 0x03)) == DIR_CODE)
		b = args[2];
	else
		b = t->reg[args[2] - 1];
	write_bytes(t->reg[args[0] - 1], t->pc + (a + b) % IDX_MOD, vm->arena);
}

void	ffork(t_process *t, t_vm *vm, int *args)
{
	t_process	*p;

	if (!(p = (t_process*)ft_memalloc(sizeof(t_process))))
		sys_error(NULL);
	p->next = vm->start;
	p->player_num = t->player_num;
	p->num = ++vm->num_process; // check if this is necessary
	p->carry = t->carry;
	p->last_live = t->last_live;
	p->exec_cycle = t->exec_cycle;
	ft_memcpy(p->reg, t->reg, REG_SIZE * REG_NUMBER);
	p->pc = (t->pc + args[0] % IDX_MOD) % MEM_SIZE;
	vm->start = p;
}

void	lld(t_process *t, t_vm *vm, int *args)
{
	t->reg[args[1] - 1] =
	(((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03) == DIR_CODE ? args[0] :
	// original corewar reads 2 bytes here instead of 4, probably a bug
	//read_dir(t->pc + args[0], vm->arena));
	read_ind(t->pc + args[0], vm->arena));
	t->carry = !t->reg[args[1] - 1];
}

void	lldi(t_process *t, t_vm *vm, int *args)
{
	int		a;
	int		b;
	t_byte	c;

	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 6) & 0x03)) == DIR_CODE)
		a = args[0];
	else if (c == IND_CODE)
		a = read_dir(t->pc + args[0] % IDX_MOD, vm->arena);
	else
		a = t->reg[args[0] - 1];
	if ((c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> 4) & 0x03)) == DIR_CODE)
		b = args[1];
	else
		b = t->reg[args[1] - 1];
	t->reg[args[2] - 1] = read_dir((t->pc + a + b) % MEM_SIZE, vm->arena);
	t->carry = !t->reg[args[2] - 1];
}

void	lfork(t_process *t, t_vm *vm, int *args)
{
	t_process	*p;

	if (!(p = (t_process*)ft_memalloc(sizeof(t_process))))
		sys_error(NULL);
	p->next = vm->start;
	p->player_num = t->player_num;
	p->num = ++vm->num_process; // check if this is necessary
	p->carry = t->carry;
	p->last_live = t->last_live;
	p->exec_cycle = t->exec_cycle;
	ft_memcpy(p->reg, t->reg, REG_SIZE * REG_NUMBER);
	p->pc = (t->pc + args[0]) % MEM_SIZE;
	vm->start = p;
}
