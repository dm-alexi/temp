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
    p->num = num;
    p->pc = pc;
    return (p);
}

void		read_instr(t_process *cur, t_vm *vm)
{
	static const unsigned	lag[OP] =
	{10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2};

	if ((cur->op = vm->arena[cur->pc]) > 0 && cur->op <= OP)
		cur->exec_cycle = vm->cycle + lag[cur->op - 1] - 1; //check if -1 is correct
	else
		cur->exec_cycle = vm->cycle;
}

void		exec_instr(t_process *cur, t_vm *vm)
{
	static void (*op[OP])(t_process*, t_vm*) = {live, ld, st, add, sub, and, or,
	xor, zjmp, ldi, sti, fork, lld, lldi, lfork, aff};

    if (cur->op > 0 && cur->op <= OP) //check argument correctness ?
	{
		op[cur->op - 1](cur, vm);
	}
	else
		cur->pc = (cur->pc + 1) % MEM_SIZE;
}
