#include <stdlib.h>

char    *ft_strncpy(char *dst, const char *src, size_t n)
{
    char    *s;

    s = dst;
    while (n && (*s++ = *src++))
        --n;
    while (n--)
        *s++ = '\0';
    return (dst);
}
