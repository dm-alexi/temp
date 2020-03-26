#include <stdlib.h>
#include "corewar.h"

void	delete_vm(t_vm *vm)
{
	t_process	*t;
	int			i;

	while (vm->start)
	{
		t = vm->start->next;
		free(vm->start);
		vm->start = t;
	}
	i = 0;
	while (i < vm->num_players)
		free(vm->players[i++].code);
	free(vm->players);
	free(vm);
}
