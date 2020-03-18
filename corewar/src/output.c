#ifdef _WIN32
# include <stdio.h>
#endif
#include <unistd.h>
#include "libft.h"
#include "corewar.h"

void	introduce(t_vm *vm)
{
	int	i;

	ft_printf("Introducing contestants...\n");
	i = -1;
	while (++i < vm->num_players)
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n", i + 1,
		vm->players[i].header.prog_size, vm->players[i].header.prog_name,
		vm->players[i].header.comment);
}

void	dump(t_vm *vm)
{
	char	*s;

	s = vm->arena;
	while (s - vm->arena + vm->dump_len <= MEM_SIZE)
	{
		write(STDOUT_FILENO, s, vm->dump_len);
		write(STDOUT_FILENO, "\n", 1);
		s += vm->dump_len;
	}
	if (s < vm->arena + vm->dump_len)
	{
		write (STDOUT_FILENO, s, vm->arena + vm->dump_len - s);
		write(STDOUT_FILENO, "\n", 1);
	}
}
