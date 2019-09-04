#include <stdlib.h>
#include "libft.h"

char    *ft_strmap(char const *s, char (*f)(char))
{
    char    *t;
    char    *str;

    if (!(str = (char*)malloc(ft_strlen(s) + 1)))
        return (NULL);
    t = str;
    while (*s)
        *t++ = f(*s++);
    *t = '\0';
    return (str);
}
