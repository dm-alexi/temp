#include <stdio.h>
#include <stdlib.h>
#include "ft_bigint.h"

int main()
{
	int sign;
	uint64_t frac;
	int exp;
	int exp10;
	double d = 0.05;

	get_double(d, &sign, &frac, &exp);
	printf("%d %I64u %d\n", sign, frac, exp);

	t_bigint tmp, pow, res;
	exp10 = 0;
	if (exp < 0)
	{
		exp10 = exp;
		ft_bigint_pow5(&pow, -exp);
	}
	else
		ft_bigint_pow2(&pow, exp);
	ft_bigint_get(&tmp, frac);
	ft_bigint_mult(&res, &tmp, &pow);
	print_bigint(&res);
	printf("\n* 10 ^ %d", exp10);

    return 0;
}
