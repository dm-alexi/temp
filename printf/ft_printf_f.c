#include <stdlib.h>
#include "ft_bigint.h"

static const int	g_pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000,
	10000000, 100000000};

char	*ft_bigint2str(t_bigint *a)
{
	char		*s;
	int			j;
	int			i;
	uint32_t	t;

	if (!(s = (char*)malloc(9 * a->len)))
		return (NULL);
	i = a->len - 1;
	while (i >= 0)
	{
		t = a->arr[i--];
		j = 8;
		while (j > 0)
		{
			*s++ = t / g_pow10[j] + '0';
			t %= g_pow10[j--];
		}
		*s++ = t + '0';
	}
    return (s - 9 * a->len);
}

int		ft_printf_f(t_format *format, t_bigint &t, int exp, char **s)
{
	char	*str;

    str = ft_bigint2str(t);

}
