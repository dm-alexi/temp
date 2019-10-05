#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
    int		l, k;
    wchar_t a = 'a', b = 'b';
    //l = ft_printf("%%dsdf%+01.5vbn\n", 1335, 78);
    l = printf("I am the %s of the %s!", "King", "world");
    printf("\n%i\n", l);
    k = ft_printf("I am the %lls of the %s!", "King", "world");
    printf("\n%i\n", k);
    //printf("%%d;", 10000000);
    //printf("%d", sizeof(wchar_t));
    l = printf("1 %-3c 2 %3c", a, b);
    printf("\n%i\n", l);
    k = ft_printf("1 %-3c 2 %3c", a, b);
    printf("\n%i\n", k);
    l = printf("First %d Second %d", 500, -10);
    printf("\n%i\n", l);
    k = ft_printf("First %d Second %d", 500, -10);
    printf("\n%i\n", k);
    //printf("%lu", sizeof(wchar_t));

    return 0;
}
