void     ft_putchar(char c);

void    ft_putstr(char *str)
{
    while (*str)
        ft_putchar(*str++);
}

int     ft_strcmp(char *s1,char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        ++s1;
        ++s2;
    }
    return (*s1 - *s2);
}

void    sort(char **arr, int n)
{
    int i;
    int j;
    char *t;

    i = 1;
    while (i < n - 1)
    {
        j = i + 1;
        while (j < n)
        {
            if (ft_strcmp(arr[i], arr[j]) > 0)
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
            ++j;
        }
        ++i;
    }
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    sort(av, ac);
    while (i < ac)
    {
        ft_putstr(av[i++]);
        ft_putchar('\n');
    }
    return 0;
}
