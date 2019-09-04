#include <stdlib.h>
#include "libft.h"

char    *ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
    int     i;
    char    *str;

    if (!(str = (char*)malloc(ft_strlen(s) + 1)))
        return (NULL);
    i = 0;
    while (*s)
    {
        *(str + i) = f(i, *s++);
        ++i;
    }
    *(str + i) = '\0';
    return (str);
}
