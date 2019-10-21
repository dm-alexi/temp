/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:22:02 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/19 19:49:18 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_bigint.h"
#include "libft/libft.h"

int floatzero(t_format *format, char **s, int sign)
{
	int		len;
	int		tmp;

	if (format->prec)
		format->sharp = 1;
	len = 1 + (sign || format->plus || format->space) +
		(format->sharp ? format->prec + 1 : 0);
	if (len > format->width)
		format->width = len;
	if (!(*s = (char*)malloc(format->width)))
		return (-1);
    ft_memset(*s, !format->minus && format->zero ? '0' : ' ', format->width);
    tmp = format->minus ? len : format->width;
    while (format->prec-- > 0)
		(*s)[--tmp] = '0';
	if (format->sharp)
		(*s)[--tmp] = '.';
	(*s)[--tmp] = '0';
	tmp = **s == '0' ? 0 : tmp - 1;
	if (sign)
		(*s)[tmp] = '-';
	else if (format->plus || format->space)
		(*s)[tmp] = format->plus ? '+' : ' ';
	return (format->width);
}

int floatspecial(t_format *format, char **s, int sign, uint64_t val)
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

int	floatlen(long double d, t_format *format, char **s)
{
    uint64_t	val;
    uint32_t	exp;
    int			sign;

    val = *((uint64_t*)&d);
    exp = *((uint64_t*)&d + 1) & 0x00007fff;
    sign = (*((uint64_t*)&d + 1) & 0x00008000) > 0;
	//printbin(&val, 8);
	//printbin(&exp, 4);
	//printf("%d\n", sign);
	if (!exp && !val)
		return (floatzero(format, s, sign));
	if (exp == 0x00007fff)
		return (floatspecial(format, s, sign, val));


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
