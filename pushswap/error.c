#include <unistd.h>
#include "libft/libft.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	a_error(const char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

int		flag_error(char c)
{
	char	s[] = "Incorrect flag: - \n";

	s[17] = c;
	write(2, s, 18);
	exit(1);
}
