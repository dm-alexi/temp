#include "corewar.h"
#include "libft.h"

int	main(int ac, char **av)
{
    t_vm	*vm;

	if (!(vm = ft_memalloc(sizeof(t_vm))))
		sys_error(NULL);
    input(vm, ac, av);
    vm->cycles_to_die = CYCLE_TO_DIE;
    vm->next_check = vm->cycles_to_die;
    vm->last_alive = vm->num_players;
    introduce(vm);
    init_arena(vm);
    if (battle(vm))
		declare_winner(vm);
    delete_vm(vm);
	return (0);
}