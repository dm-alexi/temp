int		ft_atoi(char *str)
{
	int		n;
	int		sign;

	n = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
        *str == '\v' || *str == '\f' || *str == '\r')
		++str;
	if (*str == '-' || *str == '+')
	{
		sign = *str == '-' ? -1 : 1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
		n = n * 10 + *str++ - '0';
	return (n * sign);
}
