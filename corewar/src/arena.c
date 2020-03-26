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

int		read_dir(int start, t_byte *arena)
{
	char	s[DIR_SIZE];
	int		i;

	if (start < 0)
		start += MEM_SIZE;
	if (start + DIR_SIZE < MEM_SIZE)
		return (*((int*)(arena + start)));
	i = -1;
	while (++i < DIR_SIZE)
		s[i] = arena[(start + i) % MEM_SIZE];
	return (*((int*)s));
}

int		read_ind(int start, t_byte *arena)
{
	char	s[IND_SIZE];
	int		i;

	if (start < 0)
		start += MEM_SIZE;
	if (start + IND_SIZE < MEM_SIZE)
		return (*((short*)(arena + start)));
	i = -1;
	while (++i < IND_SIZE)
		s[i] = arena[(start + i) % MEM_SIZE];
	return (*((short*)s));
}

void	write_bytes(int n, int start, t_byte *arena)
{
	t_byte	*s;
	int		i;

	if (start < 0)
		start += MEM_SIZE;
	if (start + DIR_SIZE < MEM_SIZE)
		*(int*)(arena + start) = n;
	else
	{
		s = (t_byte*)&n;
		i = -1;
		while (++i < REG_SIZE)
			arena[(start + i) % MEM_SIZE] = s[i];
	}
}
