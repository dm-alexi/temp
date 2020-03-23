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
		vm->players[i].num, i * step);
		vm->start->reg[0] = -(i + 1);
	}
}

int		readbytes(int start, t_byte *arena)
{
    char	s[DIR_SIZE];
    int		i;

	i = 0;
	if (start + DIR_SIZE < MEM_SIZE)
		return (*((int*)(arena + start)));
	while (i < DIR_SIZE)
	{
		s[i] = arena[(start + i) % MEM_SIZE];
		++i;
	}
	return (*((int*)s));
}
