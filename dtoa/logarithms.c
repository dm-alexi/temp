#include <stdint.h>

uint32_t intlog2(uint32_t val)
{
	int n = 0;

	while (val >>= 1)
		++n;
	return (n);
}
