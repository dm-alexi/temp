#include "corewar.h"
#include "libft.h"

t_process	*new_process(t_process *next, unsigned num, unsigned player_num)
{
    t_process	*p;

    if (!(p = (t_process*)ft_memalloc(sizeof(t_process))))
		sys_error(NULL);
    p->next = next;
    p->player_num = player_num;
    p->num = num;
    //p->pc = ?
    return (p);
}
