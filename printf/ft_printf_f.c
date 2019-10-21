#include <stdlib.h>
#include "libft/libft.h"
#include "ft_bigint.h"
#include "ft_printf.h"

static const int	g_pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000,
	10000000, 100000000};

int		ft_bigint2str(t_bigint *a, int exp, char *s)
{
	int			len;
	char		*t;
	int			j;
	int			i;
	uint32_t	n;

	len = (a->len * 9 > -exp ? a->len * 9 : -exp) + 1;
	if (!(s = (char*)ft_memalloc(len)))
		return (-1);
	i = a->len - 1;
	t = s + 1 + (a->len * 9 > -exp ? 0 : -exp - a->len * 9);
	while (i >= 0)
	{
		n = a->arr[i--];
		j = 8;
		while (j > 0)
		{
			*t++ = n / g_pow10[j];
			n %= g_pow10[j--];
		}
		*t++ = n;
	}
    return (len);
}

char	*ft_printf_b2f(t_format *format, t_bigint *t, int exp, int *sign)
{
	char	*str;
	int		len;
	int		i;

    if ((len = ft_bigint2str(t, exp, str)) < 0)
		return (NULL);
	i = len + exp;
//rounding here!
}
