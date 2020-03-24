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

int		skip_size(int op, t_byte c)
{
	int	n;
	int	argnum;

	if (!g_tab[op].argtype)
		return (g_tab[op].dirsize);
	argnum = g_tab[op].argnum;
	n = 1;
	while (c >>= 2)
		if (++argnum > 3)
		{
            if ((c & 0x03) == REG_CODE)
				n += T_REG;
			else if ((c & 0x03) == DIR_CODE)
				n += g_tab[op].dirsize;
			else if ((c & 0x03) == IND_CODE)
				n += T_IND;
		}
	return (n);
}

int			check_instr(t_process *cur, t_vm *vm)
{
	t_byte	c;
	int		i;
	int		n;

	i = 0;
	while (i < g_tab[cur->op].argnum)
	{
		c = ((vm->arena[(cur->pc + 1) % MEM_SIZE] >> (6 - 2 * i)) & 0x03);
        if (c == REG_CODE && (g_tab[cur->op].args[i] & T_REG) &&
		vm->arena[cur->op + 2 + n] > 0 &&
		vm->arena[cur->op + 2 + n] <= REG_NUMBER)
			++n;
		else if (c == DIR_CODE && (g_tab[cur->op].args[i] & T_DIR))
			n += g_tab[cur->op].dirsize;
		else if (c == IND_CODE && (g_tab[cur->op].args[i] & T_IND))
			n += IND_SIZE;
		else
			return (0);
		++i;
	}
	return (1);
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
    if (cur->op > 0 && cur->op <= OP)
	{
		if (!g_tab[cur->op].argtype || check_instr(cur, vm))
			g_tab[cur->op].func(cur, vm);
        if (g_tab[cur->op].func != zjmp)
			cur->pc = (cur->pc + 1 + skip_size(cur->op,
			vm->arena[(cur->pc + 1) % MEM_SIZE])) % MEM_SIZE;
	}
	else
		cur->pc = (cur->pc + 1) % MEM_SIZE;
}
