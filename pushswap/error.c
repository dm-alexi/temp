#include <unistd.h>

int		error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int		mem_error(void)
{
	write(2, "Error: memory allocation failed.\n", 33);
	return (1);
}

int		inc_flag(char c)
{
	char	s[] = "Incorrect flag: - \n";

	s[17] = c;
	write(2, s, 18);
	return (1);
}
