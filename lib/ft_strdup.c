#include <stdlib.h>
#include "libft.h"

char    *ft_strdup(const char *src)
{
    char    *s;

    if (!(s = (char*)malloc(ft_strlen(src) + 1)))
        return (NULL);
    return (ft_strcpy(s, src));
}
