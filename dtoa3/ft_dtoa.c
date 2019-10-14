#include <stdlib.h>
#include "ft_bigint.h"
#include "libft.h"

char	*ft_dtoa(double d)
{
	return (NULL);
}

void	ft_read_double(char *s, double d, int prec, int *exp10)
{

}

char	*ft_dtoa_unf(double d, int prec, int *exp10)
{
	uint64_t	val;
	uint32_t	exp;
	char		*s;
	int			i;

	if (!(s = (char*)malloc(prec + 4)))
		return (NULL);
	val = *(uint64_t*)&d;
	s[0] = (val & 0x8000000000000000 ? '-' : '+');
    if (((val & 0x7ff0000000000000)) == 0x7ff0000000000000)
		ft_strcpy(s + 1, (val & 0x000fffffffffffff) ? "nan" : "inf");
	else if (!(val & 0x7fffffffffffffff))
	{
		s[1] = '0';
		if (prec > 0)
			s[2] = '.';
		ft_memset(s + 2, '0', prec);
		s[prec > 0 ? prec + 3 : 2] = '\0';
	}
	else
		ft_read_double(s + 1, d, prec, exp10);
	return (s);
}

