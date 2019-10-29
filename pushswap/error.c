#include <unistd.h>

int		error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int		inc_flag(char c)
{
	write(2, "Incorrect flag: -", 17);
	write(2, &c, 1);
	write(2, "\n", 1);
	return (1);
}

int		usage(void)
{
	write(1, "usage: checker [-flags] [list]\n", 31);
	return (0);
}
