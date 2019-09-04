#include <stdlib.h>
#include "libft.h"

char    *ft_itoa(int n)
{
    char    *s;
    char    tmp[11];
    int     sign;

    sign = 0;
    s = tmp + 10;
    *s-- = '\0';
    if (n == 0)
        *s-- = '0';
    else if (n < 0)
    {
        sign = 1;
        *s-- = -(n % 10) + '0';
        n = -(n / 10);
    }
    while (n)
    {
        *s-- = n % 10 + '0';
        n /= 10;
    }
    if (sign)
        *s-- = '-';
    return (ft_strdup(s + 1));
}
