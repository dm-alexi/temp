#include <stdlib.h>

int ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    char    *s1;
    char    *s2;
    char    *e;

    s1 = (char *)ptr1;
    s2 = (char *)ptr2;
    e = s1 + num;
    while (s1 != e && *s1 == *s2)
    {
        ++s1;
        ++s2;
    }
    return (s1 == e ? 0 : *s1 - *s2);
}
