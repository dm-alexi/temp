#include <stdlib.h>

char    *ft_strrchr(const char *str, int character)
{
    char    c;
    char    *s;

    c = (char)character;
    s = NULL;
    while (*str)
    {
        if (*str == c)
            s = (char*)str;
        ++str;
    }
    return (c == '\0' ? (char*)str : s);
}
