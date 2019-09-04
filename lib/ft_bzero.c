#include <stdlib.h>

void    ft_bzero(void *buf, size_t n)
{
    unsigned char   *s;
    unsigned char   *e;

    s = (unsigned char*)buf;
    e = s + n;
    while (s != e)
        *s++ = '\0';
}
