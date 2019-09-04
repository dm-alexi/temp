#include <stdlib.h>
#include "libft.h"

void    *ft_memset(void *buf, int ch, size_t count)
{
    unsigned char   c;
    unsigned char   *s;
    unsigned char   *e;

    c = (unsigned char)ch;
    s = (unsigned char*)buf;
    e = s + count;
    while (s != e)
        *s++ = c;
    return (buf);
}
