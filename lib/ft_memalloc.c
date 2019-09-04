#include <stdlib.h>
#include "libft.h"

void    *ft_memalloc(size_t size)
{
    void *p;

    p = malloc(size);
    if (p)
        ft_memset(p, 0, size);
    return (p);
}
