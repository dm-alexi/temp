#include <stdlib.h>
#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t num)
{
    void    *tmp;

    if (!(tmp = malloc(num)))
        return (NULL);
    ft_memcpy(tmp, src, num);
    ft_memcpy(dst, tmp, num);
    free(tmp);
    return dst;
}
