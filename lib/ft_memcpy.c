#include <stdlib.h>

void    *ft_memcpy(void *dst, const void *src, size_t num)
{
    char    *s;
    char    *e;
    char    *t;

    t = (char*)dst;
    s = (char*)src;
    e = s + num;
    while (s != e)
        *t++ = *s++;
    return (dst);
}
