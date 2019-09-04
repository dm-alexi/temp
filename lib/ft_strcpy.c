char    *ft_strcpy(char *dst, const char *src)
{
    char    *s;

    s = dst;
    while ((*s++ = *src++))
        ;
    return (dst);
}
