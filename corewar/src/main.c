#include "corewar.h"
#include "libft.h"

int	main(int ac, char **av)
{
    t_vm	*vm;

	if (!(vm = ft_memalloc(sizeof(t_vm))))
		sys_error();

    input(vm, ac, av);
	return (0);
}
