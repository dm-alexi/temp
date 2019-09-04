int     ft_iterative_factorial(int nb)
{
    int     k;

    if (nb <= 0 || nb > 12)
        return (0);
    k = 1;
    while (nb > 1)
        k *= nb--;
    return (k);
}
