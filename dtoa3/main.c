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
	double d = 0.0000000000004;
	uint64_t *t;

	t_bigint tmp, tmp2, pow, res;
	ft_make_bigint(d, &res, &exp10);
	print_bigint(&res);
	printf(" * 10 ^ %d\n", exp10);
	//ft_bigint_round(&res, &exp10, &tmp, mexp10);
	//print_bigint(&res);
	//printf(" * 10 ^ %d\n", exp10);
	printf("%.55f \n", d);
	t = (uint64_t*)&d;
	//*t = 0xff8fffffffffffff;
	//d = 12345.56789;
	printf("%E", d);

    return 0;
}
