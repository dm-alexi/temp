#ifndef FT_BIGINT_H
#define FT_BIGINT_H

#include <stdint.h>
#define MAX_BLOCKS 35

typedef struct	s_bigInt
{
	uint32_t	len;
	uint32_t	arr[35];
}				t_bigInt;

#endif
