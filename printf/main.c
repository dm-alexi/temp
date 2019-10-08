#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int get_exponent(double d);

int main()
{
/*    int		l, k;
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
    printf("\n%i\n", k);*/
    float f = 392.6512342346;
    long double d = 392.6512342346L;
    double dub = 0.01171875;
    double tmp = -2;
    double nul = -0.0;
 /*   printf("%.12f\n", f);
    printf("%.12Lf\n", d);
    printf("%f\n", 0.0);
    printf("%d %d %d\n", sizeof(float), sizeof(double), sizeof(long double));
*/
    //unsigned char c = 128;
    unsigned char *t = (unsigned char*)&nul + 7;
    *t = *t & 0;
    int ui = (((*(uint64_t*)&dub) << 1) >> 53), ui2 = (((*(uint64_t*)&tmp) << 1 ) >> 53);
    //printbin(&c, 1);
    printbin(&dub, 8);
    printbin(&tmp, 8);
    //printbin(&nul, 8);
    //printf("%f", nul);
    printbin(&ui, sizeof(int));
    printbin(&ui2, sizeof(int));
    printf("%d %d\n", ui - 1023, ui2 - 1023);
    int64_t sign1 = ((*((int64_t*)&dub)) << 11) >> 11;
    int64_t sign2 = ((*((int64_t*)&tmp)) << 11) >> 11;
    printf("%lld %lld\n", sign1, sign2);
    printbin(&sign1, 8);
    printbin(&sign2, 8);
    printf("%d %d\n", get_exponent(dub), get_exponent(tmp));
    return 0;
}
