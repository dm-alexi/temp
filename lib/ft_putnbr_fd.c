#include <unistd.h>

void    ft_putnbr_fd(int n, int fd)
{
    char    s[10];
    char    *t;

    t = s + 9;
    *t-- = '\0';
    if (n == 0)
        *t-- = '0';
    else if (n < 0)
    {
        write(fd, "-", 1);
        *t-- = -(n % 10) + '0';
        n = -(n / 10);
    }
    while (n)
    {
        *t-- = n % 10 + '0';
        n /= 10;
    }
    write(fd, t + 1, 9 - (t - s));
}
