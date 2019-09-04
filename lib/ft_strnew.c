#include <stdlib.h>

char    *ft_strnew(size_t size)
{
    char    *str;
    char    *s;
    char    *e;

    if (!(str = (char*)malloc(size)))
        return (NULL);
    s = str;
    e = str + size;
    while (s != e)
        *s++ = '\0';
    return (str);
}
