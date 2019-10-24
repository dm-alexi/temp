#include "ft_printf.h"

static int	explen(int exp)
{
	int		i;

	i = 1;
	while ((exp /= 10) && ++i)
		;
	return (i > 2 ? i : 2);
}

//exp is negative!!!
int		ft_process_e(char **s, int exp, int len, t_format *format)
{
	char	*str;
	int		total;
	int		i;

	exp += len - 1;
	if (((format->prec + 1 < len) &&
		(ft_round(*s, len, len - 1 - format->prec)) > format->prec + 1))
		++exp;
	len = format->prec + 1;
	total = len + format->sharp + 2 + explen(exp);
	if (!(str = ft_memalloc(total)))
		return (-1);
	*str = **s;
	if (format->sharp)
		str[1] = '.';
	ft_memcpy(str + 1 + format->sharp, *s + 1, len - 1);
	str[len + format->sharp] = format->type;
	str[len + format->sharp + 1] = exp >= 0 ? '+' : '-';
	i = total;
	exp = exp >= 0 ? exp : -exp;
	while (exp && (str[--i] = exp % 10 + '0'))
		exp /= 10;
	free(*s);
	*s = str;
	return (total);
}

int		ft_printf_e(t_format *format, int len, char *str, char **s)
{
	int		i;
	int		total;

	i = -1;
	while (++i < len)
		if (str[i] >= 0 && str[i] <= 9)
			str[i] += '0';
	total = len + (format->sign != 0);
	if (format->width < total)
		format->width = total;
	if (!(*s = (char*)malloc(format->width)))
		return (-1);
	ft_memset(*s, format->fill, format->width);
	ft_memcpy(*s + (format->rpad ?
		(format->sign != 0) : total - len), str, len);
	if (format->sign)
		(*s)[**s == '0' || format->rpad ? 0 : total - len - 1] = format->sign;
	return (format->width);
}
