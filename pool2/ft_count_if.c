int     ft_count_if(char **tab, int (*f)(char*))
{
    int     n;

    n = 0;
    while (*tab)
        if (f(*tab++) == 1)
            ++n;
    return (n);
}
