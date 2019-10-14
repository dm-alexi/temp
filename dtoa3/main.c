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
	//*t = 0x7ff0000000000000;
	//*t = 0xffffffffffffffff;
	//d = 123;
	//d = 0;
	*t = 0x8000000000000000;
	printf("%.e", d);

    return 0;
}
