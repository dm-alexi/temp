#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "ft_bigint.h"

int main()
{
	int sign;
	uint64_t frac;
	int exp;
	int exp10, mexp10;
	double d = 0.1;

	get_double(d, &sign, &frac, &exp);
	//printf("%d %llu %d\n", sign, frac, exp);

	t_bigint tmp, tmp2, pow, res;
	ft_get_prev(d, &res, &exp10);
	print_bigint(&res);
	printf(" * 10 ^ %d\n", exp10);
	ft_get_next(d, &res, &exp10);
	print_bigint(&res);
	printf(" * 10 ^ %d\n", exp10);
	get_margins(d, &tmp, &tmp2, &mexp10);
	printf("                ");
	print_bigint(&tmp);
	printf(" * 10 ^ %d\n", mexp10);
	//print_bigint(&tmp2);
	//printf(" * 10 ^ %d\n", mexp10);
	ft_make_bigint(d, &res, &exp10);
	print_bigint(&res);
	printf(" * 10 ^ %d\n", exp10);
	ft_bigint_round(&res, &exp10, &tmp, mexp10);
	print_bigint(&res);
	printf(" * 10 ^ %d\n", exp10);
	printf("%.15f \n", d);
	for (int i = 0; i < 15; ++i)
	{
		d *= 10;
		printf("%d", (int)d);
		d -= (int)d;
	}
    return 0;
}
