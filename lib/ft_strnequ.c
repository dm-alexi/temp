#include <stdlib.h>

int     ft_strnequ(char const *s1, char const *s2, size_t n)
{
    while (*s1 && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	return (!(*s1 - *s2));
}
