#include "fillit.h"
#include <unistd.h>

int     get_figure(int fd)
{
    char    s[21];
    int     r;
    int     i;
    int     res;

    if (!(r = read(fd, s, 21)) < 20)
        return (r ? -1 : 0);
    res = 0;
    i = 0;
    while (i < k)
    {
        if (i % 5 == 4)
        {
            if (s[i] != '\n')
                return (0);
        }
        else if (s[i] == '.')
            res <<= 1;
        else if (s[i] == '#')
            res = ((res << 1) | 1);
        else
            return (0);
    }
    return (moveupleft(r));
}

int     *get_figures(char *s)
{
    int     fd;
    int     k;
    int     i;
    int     *res;

    if (!(res = (int*)malloc(sizeof(int) * 26)))
        exit(1);
    if ((fd = open(s)) < 0)
        return (NULL);
    i = 0;
    while ((k = get_figure(fd)) > 0)
        res[i++] = k;
    return (res);
}