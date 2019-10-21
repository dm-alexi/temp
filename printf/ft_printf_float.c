/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:22:02 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/21 18:48:49 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_bigint.h"
#include "libft/libft.h"

int		float_zero_e(t_format *format, char **s, int sign)
{
	int		len;

	return (len);
}

int		float_zero(t_format *format, char **s, int sign)
{
	int		len;

	if (format->type == 'G' || format->type == 'g')
		format->prec = format->sharp ? format->prec - 1 : 0;
	if (format->prec)
		format->sharp = 1;
	len = 1 + (sign || format->plus || format->space) +
		(format->sharp ? format->prec + 1 : 0);
	if (len > format->width)
		format->width = len;
	if (!(*s = (char*)malloc(format->width)))
		return (-1);
	ft_memset(*s, !format->minus && format->zero ? '0' : ' ', format->width);
	len = format->minus ? len : format->width;
	while (format->prec-- > 0)
		(*s)[--len] = '0';
	if (format->sharp)
		(*s)[--len] = '.';
	(*s)[--len] = '0';
	len = **s == '0' ? 0 : len - 1;
	if (sign)
		(*s)[len] = '-';
	else if (format->plus || format->space)
		(*s)[len] = format->plus ? '+' : ' ';
	return (format->width);
}

int		float_special(t_format *format, char **s, int sign, uint64_t val)
{
	int		len;
	char	*mes;

	if (val == 0x8000000000000000)
		mes = ft_isupper(format->type) ? "INF" : "inf";
	else
		mes = ft_isupper(format->type) ? "NAN" : "nan";
	len = 3 + (val != 0x8000000000000000 &&
		(sign || format->plus || format->space));
	if (format->width < len)
		format->width = len;
	if (!(*s = (char*)malloc(format->width)))
		return (-1);
	ft_memset(*s, ' ', format->width);
	len = (format->minus ? len : format->width) - 3;
	ft_memcpy(*s + len, mes, 3);
	if (sign)
		(*s)[len - 1] = '-';
	else if (format->plus)
		(*s)[len - 1] = '+';
	return (format->width);
}

int		floatlen(long double d, t_format *format, char **s)
{
	uint64_t	val;
	uint32_t	exp;
	int			exp10;
	int			sign;
	t_bigint	t;

	val = *((uint64_t*)&d);
	exp = (uint32_t)(*((uint64_t*)&d + 1)) & 0x00007fff;
	sign = (*((uint64_t*)&d + 1) & 0x00008000) > 0;
	if (!val)
		return ((format->type == 'e' || format->type == 'E') ?
			float_zero_e(format, s, sign) : float_zero(format, s, sign));
	if (exp == 0x00007fff)
		return (float_special(format, s, sign, val));
	ft_make_bigint(&t, (int)exp - 16446, val, &exp10);
	if (format->type == 'f' || format->type == 'F')
		str = ft_printf_b2f(format, &t, exp, &sign);
		//return (ft_printf_f(format, &t, exp, s));
	/*if (format->type == 'e' || format->type == 'E')
		return (ft_printf_e(format, &t, exp, s));*/

	return (0);
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
	if ((len = floatlen(d, format, &s)) < 0)
		return (-1);
	if (write(1, s, len) < len)
		len = -1;
	free(s);
	return (len);
}
