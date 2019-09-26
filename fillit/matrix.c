#include "fillit.h"

void    print_result(node **res, int n, int sq, col *root)
{
    char    *s;
    node    *j;
    int     i;
    int     k;

    if (!(s = (char*)malloc((sq + 1) * sq + 1)))
        exit(1);
    ft_memset(s, '.', (sq + 1) * sq);
    i = 0;
    while (i < n)
    {
        j = res[i]->r;
        while (j != res[i])
        {
            k = j->column - root - n - 1;
            s[k + k / sq] = 'A' + i;
            j = j->r;
        }
        ++i;
    }
    i = sq;
    while (i <= (sq + 1) * sq)
    {
        s[i] = '\n';
        i += sq + 1;
    }
    s[(sq + 1) * sq] = '\0';
    ft_putstr(s);
}