#include "corewar.h"
#include "libft.h"

static int	is_digital(char *s)
{
	if (!s || !*s)
		return (0);
	while (ft_isdigit(*s))
		++s;
	return (*s == '\0');
}

static int	valid_filename(char *s)
{
	int	n;

	return ((n = ft_strlen(s)) > 4 && ft_strequ(s + n - 4, ".cor"));
}

static int	count_players(int ac, char **av)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (++i < ac)
		if (valid_filename(av[i]))
			++count;
	return (count);
}

static char	**get_files(int ac, char **av, int n)
{
	int		i;
	int		tmp;
	char	**files;

	if (!(files = (char**)ft_memalloc(sizeof(char*) * n)))
		sys_error();
	i = 0;
    while (++i < ac)
		if (ft_strequ(av[i], "-n"))
			i < ac - 2 && is_digital(av[++i]) && (tmp = ft_atoi(av[i])) > 0 &&
			tmp <= n && valid_filename(av[++i]) && !files[tmp - 1] ?
			(files[tmp - 1] = av[i]) : error("Invalid player file or number.");
	i = 0;
	tmp = 0;
	while (++i < ac)
		if (ft_strequ(av[i], "-n"))
			i += 2;
		else if (valid_filename(av[i]))
		{
            while (files[tmp])
				++tmp;
			files[tmp] = av[i];
		}
	return (files);
}

void		input(t_vm *vm, int ac, char **av)
{
	int		i;
	char	**files;

	if (!(vm->num_players = count_players(ac, av)) ||
	vm->num_players > MAX_PLAYERS)
		error("Invalid number of players.");
	files = get_files(ac, av, vm->num_players);
    i = 0;
	while (++i < ac)
	{
		if (ft_strequ(av[i], "-d") || ft_strequ(av[i], "-dump"))
			i == ac - 1 || !is_digital(av[++i]) || vm->dump_len ?
			error("incorrect use of dump option.") :
			((vm->dump_len = (ft_strequ(av[i - 1], "-d") ? 64 : 32)) &&
			(vm->dump_cycle = ft_strtol(av[i], NULL, 10)));
		else if (ft_strequ(av[i], "-n"))
			i += 2;
		else if (!(valid_filename(av[i])))
			error_ext("invalid option ", av[i]);
	}
	get_players(vm, files);
	free(files);
}
