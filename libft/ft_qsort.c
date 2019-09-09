#include <stdlib.h>

static void memswap(void *a, void *b, size_t size)
{
    unsigned char *s;
    unsigned char *t;
    size_t i;

    s = a;
    t = b;
    i = 0;
    while (i < size)
    {
        *(s + i) ^= *(t + i);
        *(t + i) ^= *(s + i);
        *(s + i) ^= *(t + i);
        ++i;
    }
}

void ft_qsort(void* base, size_t num, size_t size,
    int (*compar)(const void*, const void*))
{
    unsigned char *l;
    unsigned char *r;
    unsigned char *p;

    if (!base || num < 2 || !size || !compar)
        return ;
    l = (unsigned char*) base;
    r = l + size * (num - 1);
    p = l + (r - l) / size / 2 * size;
    //printf("%d\n", (p - l) / size);
    //printf("%d %d\n", (l - (unsigned char *)base) / size, (r - (unsigned char *)base) / size);
    while (l <= r)
    {
        while (compar(l, p) < 0)
            l += size;
        while (compar(r, p) > 0)
            r -= size;
        if (l <= r)
        {
            memswap(l, r, size);
            l += size;
            r -= size;
        }
        //printf("%d %d\n", (l - (unsigned char *)base) / size, (r - (unsigned char *)base) / size);
    }
    //printf("%d %d\n", (l - (unsigned char *)base) / size, (r - (unsigned char *)base) / size);
    ft_qsort(base, (r - (unsigned char *)base) / size, size, compar);
    ft_qsort(l, num - (l - (unsigned char *)base) / size , size, compar);
}
