char    *ft_strcat(char *dst, const char *src)
{
    char    *s;

    s = dst;
    while (*s)
        ++s;
    while ((*s++ = *src++))
        ;
    return (dst);
}
