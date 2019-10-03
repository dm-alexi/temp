#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main()
{
    int		l;

    l = ft_printf("%%dsdf%+01.5vbn\n", 1335, 78);
    printf("%i\n", l);
    //printf("%%d;", 10000000);
    return 0;
}
