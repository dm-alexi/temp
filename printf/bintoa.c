#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void printbin(void *p, int n)
{
    char *s = (char*)malloc(n * 8 + 1);
    s[n * 8] = '\0';
    unsigned char t;
    int j = 0;
    while (j < n)
    {
        int i = 8;
        t = *((unsigned char*)p + j);
        while(i > 0)
        {
            s[(n - 1 - j) * 8 + --i] = (t & 1 ? '1' : '0');
            t >>= 1;
        }
        ++j;
    }
    printf("%s\n", s);
    free(s);
}

int get_exponent(double d)
{
    return ((int)(((*(uint64_t*)&d) << 1) >> 53) - 1023);
}

int dtoa(double value, char *s, int prec)
{
	uint64_t val;
	uint64_t frac;
	int sign;
	int32_t exp;
    int32_t exp10;
	int n = 0;

	val = *(uint64_t*)&value;
	sign = (val & 0x8000000000000000L) != 0;
	exp = (int32_t)((val << 1) >> 53) - 1023;
	//exp10 = ((((exp>>3))*77+63)>>5); // why?
    exp10 = exp * 0.301029995663981;
    frac = (val & 0x000fffffffffffff) | 0x0010000000000000;
    printf("%d %d %d\n", sign, exp, exp10);
    printbin(&frac, 8);
    
    return n;
}

//void setbin(void *p, char *s)
