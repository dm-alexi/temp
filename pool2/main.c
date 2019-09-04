#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_abs.h"
#include "ft_point.h"

char    *ft_strdup(char *src);
int     *ft_range(int min,int max);
void    ft_foreach(int *tab, int length, void(*f)(int));
int     ft_count_if(char **tab, int (*f)(char*));

void    set_point(t_point *point)
{
    point->x = 42;
    point->y = 21;
}

void    putnum(int n)
{
    printf("%d ", n);
}

int cthree(char *s)
{
    return strlen(s) == 3 ? 1 : -1;
}

int main()
{
    int *p;

    //printf(ft_strdup("Elisa\nMarch"));

    //p = ft_range(-3, 7);
    //for (int i = 0; i < 10; ++i)
    //    printf("%d ", p[i]);

    //printf("%d %d %d", ABS(-3 - 5), ABS(4 + 2), ABS(6 -5 -1 * 1));

    //t_point     point;
    //set_point(&point);

    //int s[5] = {1, 2, 3, 4, 5};
    //ft_foreach(s, 5, putnum);

    //char *s[] = {"one", "two", "three", "four", "five", "six", NULL};
    //printf("%d", ft_count_if(s, cthree));

    return 0;
}
