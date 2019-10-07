#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
    int		l, k;
    char a = 'a', b = 'b';
    //wchar_t a = L'a', b = L'b';
    //l = printf("%%dsdf%+01.5vbn\n", 1335, 78);
    //k = ft_printf("%%dsdf%+01.5vbn\n", 1335, 78);
    l = printf("I am the %s of the %s!", "King", "world");
    printf("\n%i\n", l);
    k = ft_printf("I am the %s of the %s!", "King", "world");
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
    l = printf("%Ldt", 4236789);
    printf("\n%i\n", l);
    k = ft_printf("%Ldt", 4236789);
    printf("\n%i\n", k);
    float f = 392.6512342346;
    long double d = 392.6512342346L;
    printf("%.12f\n", f);
    printf("%.12Lf\n", d);
    printf("%f\n", 0.0);
    printf("%d %d %d", sizeof(float), sizeof(double), sizeof(long double));
    return 0;
}
