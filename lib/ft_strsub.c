#include <stdlib.h>

char    *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char    *str;
    char    *t;

    if (!(str = (char*)malloc(len + 1)))
        return (NULL);
    t = str;
    s += start;
    while (t - str < len)
        *t++ = *s++;
    *t = '\0';
    return (str);
}
