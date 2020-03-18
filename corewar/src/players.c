#include <fcntl.h>
#include "libft.h"
#include "corewar.h"

void	get_players(t_vm *vm, char **files)
{
	int	i;
	int	fd;
	int	r;

	vm->players = (t_player*)malloc(sizeof(t_player) * vm->num_players);
	i = -1;
	while (++i < vm->num_players)
	{
		if ((fd = open(files[i], O_RDONLY)) < 0 ||
		(r = read(fd, &(vm->players + i)->header, sizeof(t_header))) < 0)
			sys_error_ext(files[i]);
		if (r < sizeof(t_header))
			error_ext("invalid file ", files[i]);
		//ft_printf("%x\n%s\n%u\n%s\n", vm->players[i].header.magic, vm->players[i].header.prog_name, vm->players[i].header.prog_size, vm->players[i].header.comment);
		//vm->players[i].header.prog_size = 16;
		if (vm->players[i].header.prog_size > CHAMP_MAX_SIZE)
			error_ext(files[i], " code size exceeds maximum value.");
		if (!(vm->players[i].code = (char*)malloc(vm->players[i].header.prog_size)))
			sys_error();
		if ((r = read(fd, (vm->players + i)->code,
		vm->players[i].header.prog_size)) < vm->players[i].header.prog_size)
		r < 0 ? sys_error_ext(files[i]) : error_ext("invalid file ", files[i]);
		vm->players[i].num = i + 1;
	}
}
