#include <stdlib.h>

size_t  ft_strlen(const char *str)
{
    size_t  n;

    n = 0;
    while (*str++)
        ++n;
    return (n);
}
