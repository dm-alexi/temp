#include <stdlib.h>

int     ft_strlen(char *str)
{
    int     n;

    n = 0;
    while(*str++)
        ++n;
    return (n);
}

char    *ft_strdup(char *src)
{
    int     n;
    char    *s;
    char    *t;

    n = ft_strlen(src);
    s = (char*)malloc(n + 1);
    t = s;
    while ((*t++ = *src++))
        ;
    return (s);
}
