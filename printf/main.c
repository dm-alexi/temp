#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"

#include <limits.h>

int	floatlen(long double d, t_format *format, char **s);

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
    long double dub = 0.01171875;
    long double tmp = -1;
    double nul = -0.0;
    int i;
/*
    ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
    printf("@moulitest: %#.o %#.0o\n", 0, 0);
    ft_printf("@moulitest: %.x %.0x\n", 0, 0);
    printf("@moulitest: %.x %.0x\n", 0, 0);
    ft_printf("%#o\n", 0);
    printf("%#o\n", 0);
    ft_printf("%o\n", 0);
    printf("%o\n", 0);
    ft_printf("%.5p\n", 0);
    printf("%.5p\n", 0);
    //printf("%05p", 0);
*/
    //printbin(&dub, 16);
    //printbin(&nul, 12);
    //floatlen(nul, NULL, NULL);

    long double l = dub;
    uint64_t	*man = (uint64_t*)&l;
    uint32_t	*exp = (uint32_t*)(((uint64_t*)&l) + 1);
    //printf("%Lf\n", l);
    //*man = 0xffffffffffffffff;
    //*man = 0;
    *man = 0x8000000000000000;
    *exp = 0x00007fff;
    printbin(man, 8);
    printbin(exp, 4);
    printf("%.10g!\n", 0.0);
	printf("%#.10g!\n", 0.0);
	ft_printf("%.10g!\n", 0.0);
	ft_printf("%#.10g!\n", 0.0);
	//printf("%-015f!\n", 0.325);


    return 0;
}
