#include "corewar.h"
#include "libft.h"

void	init_arena(t_vm *vm)
{
	int	i;
	int	step;

	step = MEM_SIZE / vm->num_players;
	i = -1;
	while (++i < vm->num_players)
	{
		ft_memcpy(vm->arena + i * step, vm->players[i].code,
		vm->players[i].header.prog_size);
        vm->start = new_process(vm->start, ++vm->num_process,
		vm->players[i].num);
	}
}
