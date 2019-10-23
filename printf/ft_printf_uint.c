/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:35:11 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/23 19:07:40 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

static int			uintmaxlen(uintmax_t n, char **s, t_format *format, int b)
{
	int		len;
	int		apostrophes;

	len = (!n && format->prec);
	apostrophes = 0;
	while (n && ++len)
		n /= b;
	if (format->sharp && b == 8)
		format->prec = format->prec <= len ? len + 1 : format->prec;
	if (format->sharp && b == 16)
		format->prec = format->prec <= len - 1 ? len + 2 : format->prec;
	if (format->apost && b == 10 && len > 3)
		apostrophes = (len - 1) / 3;
	if (len < format->prec)
		len = format->prec;
	len += apostrophes;
	if (!format->rpad && len < format->width)
		len = format->width;
	if (!(*s = (char*)malloc(len)))
		return (-1);
	ft_memset(*s, format->fill, len);
	return (len);
}

static int			uintmaxtoa(uintmax_t n, char **s, t_format *format)
{
	int		len;
	int		tmp;
	int		count;
	int		base;

	base = format->type == 'u' ? 10 : 8;
	if ((len = uintmaxlen(n, s, format, base)) <= 0)
		return (len);
	tmp = len;
	count = 0;
	if (!n && format->prec)
		(*s)[--tmp] = '0';
	while (n || format->prec > 0)
	{
		(*s)[--tmp] = n % base + '0';
		n /= base;
		--format->prec;
		if (format->apost && base == 10 && !(++count % 3))
			(*s)[--tmp] = '\'';
	}
	return (len);
}

static int			base16toa(uintmax_t n, char **s, t_format *format)
{
	int		len;
	int		tmp;
	int		digit;

	if ((len = uintmaxlen(n, s, format, 16)) <= 0)
		return (len);
	tmp = len;
	if (!n && format->prec)
		(*s)[--tmp] = '0';
	while (n || format->prec > 0)
	{
		if ((digit = n % 16) < 10)
			(*s)[--tmp] = digit + '0';
		else
			(*s)[--tmp] = digit - 10 + (format->type == 'X' ? 'A' : 'a');
		n /= 16;
		--format->prec;
	}
	if (format->sharp)
		(*s)[**s == '0' ? 1 : tmp + 1] = format->type;
	return (len);
}

static uintmax_t	get_uinteger(t_format *format, va_list *va)
{
	if (!format->length)
		return ((unsigned int)va_arg(*va, unsigned int));
	if (format->length == 'H')
		return ((unsigned char)va_arg(*va, unsigned int));
	if (format->length == 'h')
		return ((unsigned short)va_arg(*va, unsigned int));
	if (format->length == 'l')
		return ((unsigned long)va_arg(*va, unsigned long));
	if (format->length == 'L')
		return ((unsigned long long)va_arg(*va, unsigned long long));
	if (format->length == 'j')
		return ((uintmax_t)va_arg(*va, uintmax_t));
	if (format->length == 'z')
		return ((size_t)va_arg(*va, size_t));
	//check uintptr_t (see man) - fixed... kinda
	if (format->length == 't')
		return ((uintptr_t)va_arg(*va, uintptr_t));
	return ((unsigned int)va_arg(*va, unsigned int));
}

int					ft_printf_uint(t_format *format, va_list *va)
{
	uintmax_t	uinteger;
	char		*s;
	int			len;
	int			total_len;
	int			offset;

	uinteger = get_uinteger(format, va);
	if (format->prec >= 0)
		format->fill = ' ';
	if (!uinteger && (format->type == 'x' || format->type == 'X'))
		format->sharp = 0;
	if (format->type == 'u' || format->type == 'o')
		len = uintmaxtoa(uinteger, &s, format);
	else
		len = base16toa(uinteger, &s, format);
	if (len < 0)
		return (-1);
	offset = (format->width > len ? format->width - len : 0);
	total_len = len + offset;
	if (write(1, s, len) < len ||
	(format->rpad && ft_printf_pad(1, format->fill, offset) < offset))
		total_len = -1;
	free(s);
	return (total_len);
}
