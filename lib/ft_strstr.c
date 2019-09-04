#include <stdlib.h>
#include "libft.h"

//todo: slow version

static int *prefix(const char *s)
{
    int     *p;
    int     i;
    int     k;
    int     n;

    n = ft_strlen(s);
    p = (int*)malloc(sizeof(int) * n);
    k = -1;
    i = 1;
    p[0] = 0;
    while (i < n)
    {
        if (s[i] == s[k + 1])
            p[i++] = k + 1;
        else if (k == -1)
            p[i++] = 0;
        else
            k = s[k];
    }
    return (p);
}
#include <stdio.h>
char    *ft_strstr(const char *s1, const char *s2)
{
    int     *p;
    int     i;

    p = prefix(s2);
    for (int i = 0; i < ft_strlen(s2); ++i)
        printf("%d ", p[i]);
    return NULL;
}
