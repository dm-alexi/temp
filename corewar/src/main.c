#include "corewar.h"
#include "libft.h"

int	main(int ac, char **av)
{
    t_vm	*vm;

	if (!(vm = ft_memalloc(sizeof(t_vm))))
		sys_error(NULL);
    input(vm, ac, av);
    introduce(vm);
    init_arena(vm);
    delete_vm(vm);
	return (0);
}
