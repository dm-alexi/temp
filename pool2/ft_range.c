#include <stdlib.h>

int     *ft_range(int min, int max)
{
    int     *p;
    int     *k;
    int     n;

    if (min >= max)
        return (NULL);
    n = max - min;
    p = (int*)malloc(sizeof(int) * n);
    k = p;
    while (min < max)
        *k++ = min++;
    return (p);
}
