/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:28:39 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/12 02:16:14 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

static void	kill_process(t_vm *vm, t_process *p)
{
	if (vm->verbosity & DEATHS)
		ft_printf("Process %u hasn't lived for %d cycles (CTD %d)\n", p->num,
		vm->cycle - p->last_live, vm->cycles_to_die);
	free(p);
	--vm->num_process;
}

static void	kill_processes(t_vm *vm)
{
	t_process	*t;
	t_process	*tmp;

	while (vm->start && vm->start->last_live <= vm->cycle - vm->cycles_to_die)
	{
		tmp = vm->start->next;
		kill_process(vm, vm->start);
		vm->start = tmp;
	}
	if (!(t = vm->start))
		return ;
	while (t->next)
		if (t->next->last_live <= vm->cycle - vm->cycles_to_die)
		{
			tmp = t->next->next;
			kill_process(vm, t->next);
			t->next = tmp;
		}
		else
			t = t->next;
}

static int	check(t_vm *vm)
{
	kill_processes(vm);
	if (!vm->start)
		return (1);
	if (++vm->checks == MAX_CHECKS || vm->live_calls >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checks = 0;
		if (vm->verbosity & CYCLES)
			ft_printf("Cycle to die is now %d", vm->cycles_to_die);
	}
	vm->live_calls = 0;
	vm->next_check = vm->cycle + vm->cycles_to_die;
	return (0);
}

int			battle(t_vm *vm)
{
	t_process	*cur;

	while (++vm->cycle)
	{
		if (vm->verbosity & CYCLES)
			ft_printf("It is now cycle %u\n", vm->cycle);
		if (vm->dump_len && vm->dump_cycle < vm->cycle)
			return (dump(vm));
		cur = vm->start;
		while (cur)
		{
			if (cur->exec_cycle < vm->cycle)
				read_instr(cur, vm);
			if (cur->exec_cycle == vm->cycle)
				exec_instr(cur, vm);
			cur = cur->next;
		}
		if (vm->cycle >= vm->next_check && check(vm))
			break ;
	}
	return (1);
}
