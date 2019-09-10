#include <stdlib.h>
#include "libft.h"

/*
** Insertion sort. Stable.
*/

void ft_isort(void* base, size_t num, size_t size,
    int (*compar)(const void*, const void*))
{
    unsigned char *b;
    unsigned char *s;
    unsigned char *t;

    if (!base || num < 2 || !size || !compar)
        return ;
    b = (unsigned char*)base;
    s = b;
    while ((s - b) / size < num)
    {
        t = s;
        while (t > b && compar(t - size, t) > 0)
        {
            ft_memswap(t, t - size, size);
            t -= size;
        }
        s += size;
    }
}
