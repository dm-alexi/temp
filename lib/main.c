#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void plusone(char *s) { ++*s; }
void plusodd(unsigned int i, char *s) { *s += i % 2; }

int main()
{
    // bzero
    /*
    int p[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i)
        printf("%d ", p[i]);
    ft_bzero(p + 2, 8);
    for (int i = 0; i < 5; ++i)
        printf("%d ", p[i]);
    */

    // memalloc
    /*
    int *p;
    p = ft_memalloc(32);
    for (int i = 0; i < 4; ++i)
        printf("%d ", p[i]);
    */

    // memset
    /*
    char s[] = "I don't like Linux!";
    printf("%s\n", s);
    ft_memset(s + 2, '-', 5);
    printf("%s\n", s);
    */

    // strclr
    /*
    char s[] = "01234";
    ft_strclr(s);
    printf("%s", s);
    */

    // striter
    /*
    char s[] = "01234";
    ft_striter(s, plusone);
    printf("%s", s);
    */

    // striteri
/*
    char s[] = "01234";
    ft_striteri(s, plusodd);
    printf("%s", s);
*/
/*
    ft_putnbr(0);
    ft_putchar('\n');
    ft_putnbr(10);
    ft_putchar('\n');
    ft_putnbr(55491);
    ft_putchar('\n');
    ft_putnbr(-55491);
    ft_putchar('\n');
    ft_putnbr(2147483647);
    ft_putchar('\n');
    ft_putnbr(-2147483648);
    ft_putchar('\n');
*/
    //printf("%d\t%d", ft_atoi("222222222222"), atoi("222222222222"));

    //printf(ft_strsub("0123456789", 5, 4));

    //printf(ft_strjoin("Need ", "to know!"));

    /*
    printf(ft_strtrim("  ab  ac \t ad\n"));
    printf(ft_strtrim("  ab  ac \t ad"));
    printf(ft_strtrim("\tpilot "));
    printf(ft_strtrim("a"));
*/
/*
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(10));
    printf("%s\n", ft_itoa(55491));
    printf("%s\n", ft_itoa(-55491));
    printf("%s\n", ft_itoa(2147483647));
    printf("%s\n", ft_itoa(-2147483648));
    */
/*    
	printf("%s\n", ft_strstr("", "abcdabcabcdabcdab"));
    printf("%s\n", ft_strstr("abcdabcabcdabcdab", "ab"));
	printf("%s\n", ft_strstr("abcdabcabcdabcdab", "ca"));
	printf("%s\n", ft_strstr("abcdabcabcdabcdab", "dab"));
	printf("%s\n", ft_strstr("abcdabcabcdabcdab", "abc"));
	printf("%s\n", ft_strstr("abcdabcabcdabcdab", "fg"));
*/
	
//	char **arr = ft_strsplit("*hello*fellow***students*", '*');
	char **arr = ft_strsplit("****", '*');
	int i = 0;
	while (arr[i])
		printf("%s\n", arr[i++]);
	
    return 0;
}
