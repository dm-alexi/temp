#include "pushswap.h"
#include "libft/libft.h"

int		get_flags(int ac, char **av, t_flags *flags)
{
    int		i;
    char	*s;

    i = 0;
    ft_bzero(flags, sizeof(t_flags));
    while (++i < ac)
	{
		s = av[i];
		if (*s != '-' || ft_isdigit(*++s))
			return (ac - i);
        while (*s && ft_strchr("cfv", *s))
		{
			if (*s == 'c')
				flags->colored = 1;
			else if (*s == 'v')
				flags->debug = 1;
			else
				flags->filename = av[++i];
			++s;
		}
		if (*s)
			exit(inc_flag(*s));
	}
	return (0);
}

int		get_args(t_flags *flags, int n, char **av, int *a)
{

}
