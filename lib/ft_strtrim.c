#include <stdlib.h>
#include "libft.h"

char    *ft_strtrim(char const *s)
{
    char    *str;
    char    *e;

    while (*s == ' ' || *s == '\t' || *s == '\n')
        ++s;
    if (*s == '\0')
        return (ft_strdup(s));
    e = (char *)s;
    while (*e)
        ++e;
    while (*--e == ' ' || *e == '\t' || *e == '\n')
        ;
    if (!(str = (char*)malloc(e - s + 2)))
        return (NULL);
    ft_strncpy(str, s, e - s + 1);
    *(str + (e - s + 1)) = '\0';
    return (str);
}
