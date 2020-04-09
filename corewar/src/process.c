/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:30:41 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/09 18:20:41 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

t_process	*new_process(t_process *next, unsigned num, unsigned player_num,
						t_byte pc)
{
	t_process	*p;

	if (!(p = (t_process*)ft_memalloc(sizeof(t_process))))
		sys_error(NULL);
	p->next = next;
	p->player_num = player_num;
	p->num = num; // check if this is necessary
	p->pc = pc;
	return (p);
}

int			check_args(t_process *t, t_vm *vm)
{
	t_byte	c;
	int		i;
	int		n;
	int		sign;

	if (!g_tab[t->op].argtype)
		return (g_tab[t->op].dirsize);
	i = -1;
	n = 1;
	sign = 1;
	while (++i < g_tab[t->op].argnum &&
	(c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> (6 - 2 * i)) & 0x03)))
	{
		if (c == REG_CODE && (sign = (g_tab[t->op].args[i] & T_REG) &&
		(vm->arena[(t->pc + 1 + n) % MEM_SIZE] > 0) &&
		vm->arena[(t->pc + 1 + n) % MEM_SIZE] <= REG_NUMBER ? sign : -1))
			++n;
		else if (c == DIR_CODE && (n += g_tab[t->op].dirsize))
			sign = (g_tab[t->op].args[i] & T_DIR) ? sign : -1;
		else if (c == IND_CODE && (n += IND_SIZE))
			sign = (g_tab[t->op].args[i] & T_IND) ? sign : -1;
	}
	return (c ? n * sign : -n);
}

void		get_args(t_process *t, t_vm *vm, int *args)
{
	t_byte	c;
	int		i;
	int		p;

	p = t->pc + 2;
	i = -1;
	if (!g_tab[t->op].argtype)
		args[0] = (g_tab[t->op].dirsize == DIR_SIZE ?
		read_dir(p - 1, vm->arena) : read_ind(p - 1, vm->arena));
	else
		while (++i < g_tab[t->op].argnum &&
		(c = ((vm->arena[(t->pc + 1) % MEM_SIZE] >> (6 - 2 * i)) & 0x03)))
			if (c == REG_CODE)
				args[i] = vm->arena[p++ % MEM_SIZE];
			else if (c == DIR_CODE)
			{
				args[i] = (g_tab[t->op].dirsize == DIR_SIZE ?
				read_dir(p, vm->arena) : read_ind(p, vm->arena));
				p += g_tab[t->op].dirsize;
			}
			else if (c == IND_CODE)
			{
				args[i] = read_ind(p, vm->arena);
				p += IND_SIZE;
			}
}

void		read_instr(t_process *cur, t_vm *vm)
{
	if ((cur->op = vm->arena[cur->pc]) > 0 && cur->op <= OP)
		cur->exec_cycle = vm->cycle + g_tab[cur->op].lag - 1; //check if -1 is correct
	else
		cur->exec_cycle = vm->cycle;
}

void		exec_instr(t_process *cur, t_vm *vm)
{
	static int	args[3];
	int			n;

	if (cur->op > 0 && cur->op <= OP)
	{
		n = check_args(cur, vm);
		if (n <= 0)
			cur->pc = (cur->pc + 1 - n) % MEM_SIZE;
		else
		{
			get_args(cur, vm, args);
			g_tab[cur->op].func(cur, vm, args);
			if (g_tab[cur->op].func != zjmp)
				cur->pc = (cur->pc + 1 + n) % MEM_SIZE;
		}
	}
	else
		cur->pc = (cur->pc + 1) % MEM_SIZE;
}
