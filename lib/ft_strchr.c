#include <stdlib.h>

char    *ft_strchr(const char *str, int character)
{
    char    c;

    c = (char)character;
    while (*str != c && *str)
        ++str;
    return (*str == c ? (char *)str : NULL);
}
