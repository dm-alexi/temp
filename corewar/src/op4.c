#ifdef _WIN32
# include <stdio.h>
#endif
#include <unistd.h>
#include "corewar.h"

void	aff(t_process *t, t_vm *vm, int *args)
{
	char	c;

	c = t->reg[args[0] - 1];
	write(STDOUT_FILENO, &c, 1);
}
