#include <stdlib.h>

void *bsearch(const void *key, const void *base, size_t num,
    size_t size, int (*compar)(const void *, const void *))
{
    int k;
    const unsigned char *l;
    const unsigned char *r;
    const unsigned char *m;

    if (!key || !base || !num || !size || !compar)
        return (NULL);
    l = (const unsigned char*) base;
    r = l + size * (num - 1);
    while (l <= r)
    {
        m = l + (r - l) / size / 2 * size;
        if ((k = compar(key, m) < 0))
            r = m - size;
        else if (k > 0)
            l = m + size;
        else
            return ((void*)m);
    }
    return NULL;
}
