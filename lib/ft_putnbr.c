#include <unistd.h>

void    ft_putnbr(int n)
{
    char    s[10];
    char    *t;

    t = s + 9;
    *t-- = '\0';
    if (n == 0)
        *t-- = '0';
    else if (n < 0)
    {
        write(1, "-", 1);
        *t-- = -(n % 10) + '0';
        n = -(n / 10);
    }
    while (n)
    {
        *t-- = n % 10 + '0';
        n /= 10;
    }
    write(1, t + 1, 9 - (t - s));
}
