/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:46:55 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/24 22:26:05 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

static const int	g_pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000,
	10000000, 100000000, 1000000000};

static int	intlen(uint32_t n)
{
	int		i;

	i = 1;
	while (n >= g_pow10[i])
		++i;
	return (i);
}

void			ft_getrawstring(t_bigint *t, char *s, int len)
{
	int			i;
	int			j;
	uint32_t	n;

	j = len - (t->len - 1) * 9 - 1;
	i = t->len - 1;
	n = t->arr[i--];
	while (j >= 0)
	{
		*s++ = n / g_pow10[j];
		n %= g_pow10[j--];
	}
	while (i >= 0 && (j = 8))
	{
		n = t->arr[i--];
		while (j >= 0)
		{
			*s++ = n / g_pow10[j];
			n %= g_pow10[j--];
		}
	}
}

int	ft_round(char *s, int len, int hollow)
{
	int		i;

	if (s[i = len - hollow] > 5)
		++s[len - 1 - hollow];
	else if (s[i] == 5)
	{
		while (++i < len && !s[i])
			;
		if (i < len || s[len - 1 - hollow] % 2)
			++s[len - 1 - hollow];
	}
	i = len - 1 - hollow;
	while (i > 0 && s[i] == 10)
	{
		s[i--] = 0;
		++s[i];
	}
	if (s[0] == 10)
	{
		s[0] = 0;
		ft_memmove(s + 1, s, len - hollow);
		s[0] = 1;
		++len;
	}
	return (len - hollow);
}

int		ft_process_f(char **s, int exp, int len, int prec)
{
	char	*str;
	int		total;

	total = exp + 1 > len ? exp + 1 : len;
	if (prec > exp)
		total += prec - exp;
	if (total > len)
	{
		if (!(str = ft_memalloc(total)))
			return (-1);
		ft_memcpy(str + (exp + 1 > len ? exp + 1 - len : 0), *s, len);
		free(*s);
		*s = str;
	}
	if (prec < exp)
		total = ft_round(*s, total, exp - prec);
	return (total);
}

int		add_sign_width(t_format *format, int len, char **s)
{
	char	*tmp;
	int		total;

	total = len + (format->sign != 0);
	if (format->width > total)
		total = format->width;
	if (total == len)
		return (len);
	if (!(tmp = (char*)malloc(total)))
		return (-1);
	ft_memset(tmp, format->fill, total);
	ft_memcpy(tmp + (format->rpad ?
		(format->sign != 0) : total - len), *s, len);
	if (format->sign)
		tmp[*tmp == '0' || format->rpad ? 0 : total - len - 1] = format->sign;
	free(*s);
	*s = tmp;
	return (total);
}
/*
int			ft_printf_f(t_format *format, int len, char *str, char **s)
{
	int		total;
	int		i;
	int		j;

	i = 0;
	while (i < len)
		str[i++] += '0';
	total = len + format->sharp +
		(format->apost ? (len - format->prec - 1) / 3 : 0);
	if (!((*s) = (char*)malloc(total)))
		return (-1);
	j = len - format->prec;
	ft_memcpy(*s + total - format->prec, str + j, format->prec);
	if (format->sharp)
		(*s)[total - format->prec - 1] = '.';
	i = total - format->prec - 1 - format->sharp;
	while (--j >= 0)
	{
		(*s)[i--] = str[j];
		if (format->apost && !((len - format->prec - j) % 3))
			(*s)[i--] = '\'';
	}
	return (add_sign_width(format, total, s));
}
*/
int		ft_process_gf(char **s, int exp, int len, t_format *format)
{
	char	*str;
	int		total;
	int		tmp;

	format->prec -= len - exp;
	total = exp + 1 > len ? exp + 1 : len;
	if (format->prec > exp)
		total += format->prec - exp;
	if (total > len)
	{
		if (!(str = ft_memalloc(total)))
			return (-1);
		ft_memcpy(str + (exp + 1 > len ? exp + 1 - len : 0), *s, len);
		free(*s);
		*s = str;
	}
	if (format->prec < exp)
	{
		tmp = ft_round(*s, total, exp - format->prec);
		if ((total -= exp - format->prec) < tmp)
			--(format->prec);
	}
	return (total);
}

int			cut_tail(char **s, int total)
{
	while ((*s)[total - 1] == '0')
		--total;
	if ((*s)[total - 1] == '.')
		--total;
	return (total);
}

int			ft_printf_f(t_format *format, int len, char *str, char **s)
{
	int		total;
	int		i;
	int		j;

	i = 0;
	while (i < len)
		str[i++] += '0';
	total = len + (format->sharp || format->prec > 0) +
		(format->apost ? (len - format->prec - 1) / 3 : 0);
	if (!((*s) = (char*)malloc(total)))
		return (-1);
	j = len - format->prec;
	ft_memcpy(*s + total - format->prec, str + j, format->prec);
	if (format->sharp || format->prec > 0)
		(*s)[total - format->prec - 1] = '.';
	i = total - format->prec - 1 - (format->sharp || format->prec > 0);
	while (--j >= 0)
	{
		(*s)[i--] = str[j];
		if (format->apost && !((len - format->prec - j) % 3))
			(*s)[i--] = '\'';
	}
	if (ft_toupper(format->type) == 'G' && format->prec > 0 && !format->sharp)
		total = cut_tail(s, total);
	return (add_sign_width(format, total, s));
}

int			ft_printf_efg(t_format *format, t_bigint *t, int exp, char **s)
{
	char	*str;
	int		len;

	len = (t->len - 1) * 9 + intlen(t->arr[t->len - 1]);
	if (!(str = (char*)malloc(len)))
		return (-1);
	ft_getrawstring(t, str, len);
	if ((format->type == 'f' || format->type == 'F') &&
	(((len = ft_process_f(&str, exp, len, format->prec)) < 0) ||
	(len = ft_printf_f(format, len, str, s)) < 0))
		len = -1;
	else if ((format->type == 'e' || format->type == 'E') &&
	(((len = ft_process_e(&str, -exp, len, format)) < 0) ||
	(len = ft_printf_e(format, len, str, s)) < 0))
		len = -1;
	else if (((format->type == 'g' || format->type == 'G') &&
	(-exp + len - 1 < -4 || -exp + len - 1 >= format->prec)) &&
	(((len = ft_process_ge(&str, -exp, len, format)) < 0) ||
	(len = ft_printf_ge(format, len, str, s)) < 0))
		len = -1;
	else if (((format->type == 'g' || format->type == 'G') &&
	!(-exp + len - 1 < -4 || -exp + len - 1 >= format->prec)) &&
	(((len = ft_process_gf(&str, exp, len, format)) < 0) ||
	(len = ft_printf_f(format, len, str, s)) < 0))
		len = -1;
	free(str);
	return (len);
}
