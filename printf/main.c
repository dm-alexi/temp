#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"
#include <float.h>

#include <limits.h>

int main()
{
   /* int		m, k;
    char a = 'a', b = 'b';
    m = printf("%%dsdf%+01.5vbn\n", 1335, 78);
    k = ft_printf("%%dsdf%+01.5vbn\n", 1335, 78);
    m = printf("I am the %s of the %s!", "King", "world");
    printf("\n%i\n", m);
    k = ft_printf("I am the %s of the %s!", "King", "world");
    printf("\n%i\n", k);
    printf("%%d;", 10000000);
    printf("%d", sizeof(wchar_t));
    m = printf("1 %-3c 2 %3c", a, b);
    printf("\n%i\n", m);
    k = ft_printf("1 %-3c 2 %3c", a, b);
    printf("\n%i\n", k);
    m = printf("First %d Second %d", 500, -10);
    printf("\n%i\n", m);
    k = ft_printf("First %d Second %d", 500, -10);
    printf("\n%i\n", k);
    m = printf("%lldt", 4236789ll);
    printf("\n%i\n", m);
    k = ft_printf("%lldt", 4236789ll);
    printf("\n%i\n", k);*/
    float f = 392.6512342346;
    long double d = 392.6512342346L;
    long double dub = 0.01171875;
    long double tmp = -1;
    double nul = -0.0;
    int i;

    long double l = LDBL_MIN;
    uint64_t	*man = (uint64_t*)&l;
    uint32_t	*exp = (uint32_t*)(((uint64_t*)&l) + 1);

    printf("%Lf\n", l);
    ft_printf("%Lf\n", l);
    //*man = 0xffffffffffffffff;
    //*man = 0;
    //*man = 0x8000000000000000;
    //*exp = 0x00007fff;
    //printbin(man, 8);
    //printbin(exp, 2);
    ft_printf("%Lf\n", l);
    printf("%Lf\n", l);

    d = (double)INT_MIN;

    ft_printf("%17Le!\n", d);

 /*   ft_printf("%Lg!\n", d);
    ft_printf("%Lf!\n", d);
    printf("---\n");
    printf("%LE!\n", d);
    printf("%Lg!\n", d);
    printf("%Lf!\n", d);
    printf("---\n");
    d = 0.25234523450;
    ft_printf("%LE!\n", d);
    ft_printf("%Lg!\n", d);
    ft_printf("%Lf!\n", d);
    printf("---\n");
    printf("%LE!\n", d);
    printf("%Lg!\n", d);
    printf("%Lf!\n", d);
    printf("---\n");
*/
    return 0;
}
