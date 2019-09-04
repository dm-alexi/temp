#include <stdlib.h>

char    *ft_strncat(char *dst, const char *src, size_t n)
{
    char    *s;

    s = dst;
    while (*s)
        ++s;
    while (n && (*s++ = *src++))
        --n;
    *s = '\0';
    return (dst);
}
