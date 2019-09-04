#include <stdlib.h>
#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    char    *t;

    if (!(str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
        return (NULL);
    t = str;
    while (*s1)
        *t++ = *s1++;
    while ((*t++ = *s2++))
        ;
    return (str);
}
