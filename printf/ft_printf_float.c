/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:22:02 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/21 23:38:32 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_bigint.h"

int		float_zero_e(t_format *format, char **s)
{
	int		len;

	return (len);
}

int		float_zero_fg(t_format *format, char **s)
{
	int		len;

	if (format->type == 'G' || format->type == 'g')
		format->prec = format->sharp ? format->prec - 1 : 0;
	if (format->prec)
		format->sharp = 1;
	len = 1 + (format->sign != 0) +	(format->sharp ? format->prec + 1 : 0);
	if (len > format->width)
		format->width = len;
	if (!(*s = (char*)malloc(format->width)))
		return (-1);
	ft_memset(*s, format->fill, format->width);
	len = format->rpad ? len : format->width;
	while (format->prec-- > 0)
		(*s)[--len] = '0';
	if (format->sharp)
		(*s)[--len] = '.';
	(*s)[--len] = '0';
	len = **s == '0' ? 0 : len - 1;
	if (format->sign)
		(*s)[len] = format->sign;
	return (format->width);
}

int		float_special(t_format *format, char **s, uint64_t val)
{
	int		len;
	char	*mes;

	if (val == 0x8000000000000000)
		mes = ft_isupper(format->type) ? "INF" : "inf";
	else
		mes = ft_isupper(format->type) ? "NAN" : "nan";
	len = 3 + (val != 0x8000000000000000 && format->sign != 0);
	if (format->width < len)
		format->width = len;
	if (!(*s = (char*)malloc(format->width)))
		return (-1);
	ft_memset(*s, ' ', format->width);
	len = (format->rpad ? len : format->width) - 3;
	ft_memcpy(*s + len, mes, 3);
	if (format->sign)
		(*s)[len - 1] = format->sign;
	return (format->width);
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

int		floatlen(long double d, t_format *format, char **s)
{
	uint64_t	val;
	uint32_t	exp;
	int			exp10;
	int			len;
	t_bigint	t;

	val = *((uint64_t*)&d);
	exp = (uint32_t)(*((uint64_t*)&d + 1)) & 0x00007fff;
	if ((*((uint64_t*)&d + 1) & 0x00008000) > 0)
		format->sign = '-';
	if (!val)
		return ((format->type == 'e' || format->type == 'E')
		? float_zero_e(format, s) : float_zero_fg(format, s));
	if (exp == 0x00007fff)
		return (float_special(format, s, val));
	exp10 = ft_make_bigint(&t, (int)exp - 16446, val);
	if ((len = ft_printf_efg(format, &t, exp10, s)) >= 0)
		len = add_sign_width(format, len, s);
	return (len);
}

int		ft_printf_float(t_format *format, va_list *va)
{
	long double		d;
	char			*s;
	int				len;

	d = (format->length == 'L') ?
		va_arg(*va, long double) : (long double)va_arg(*va, double);
	if (format->prec < 0)
		format->prec = 6;
	if (format->prec > 0)
		format->sharp = 1;
	s = NULL;
	if ((len = floatlen(d, format, &s)) < 0)
		return (-1);
	if (write(1, s, len) < len)
		len = -1;
	free(s);
	return (len);
}
