/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:35:11 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/16 23:23:17 by sscarecr         ###   ########.fr       */
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
	int		prefix;
	int		apostrophes;

	len = (!n && format->precision);
	apostrophes = 0;
	prefix = 0;
	if ((format->flags & 8) && ft_strchr("oxX", format->specifier))
		prefix = format->specifier == 'o' ? 1 : 2;
	while (n && ++len)
		n /= b;
	if ((format->flags & 32) && len > 3)
		apostrophes = (len - 1) / 3;
	if (len < format->precision)
		len = format->precision;
	len += apostrophes + prefix;
	if (!(*s = (char*)malloc(len)))
		return (-1);
	ft_memset(*s, '0', len);
	return (len);
}

static int			uintmaxtoa(uintmax_t n, char **s, t_format *format, int b)
{
	int		len;
	int		tmp;
	int		digit;
	int		count;

	if ((len = uintmaxlen(n, s, format, b)) <= 0)
		return (len);
	tmp = len;
	count = 0;
	if (b == 16 && (format->flags & 8))
		(*s)[1] = format->specifier;
	while (n)
	{
		if ((digit = n % b) < 10)
			(*s)[--tmp] = digit + '0';
		else
			(*s)[--tmp] = digit - 10 + (format->specifier == 'x' ? 'a' : 'A');
		n /= b;
		if ((format->flags & 32) && !(++count % 3))
			(*s)[--tmp] = '\'';
	}
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
	if (format->length == 't')
		return ((ptrdiff_t)va_arg(*va, ptrdiff_t));
	return ((unsigned int)va_arg(*va, unsigned int));
}

int					ft_printf_uint(t_format *format, va_list *va)
{
	uintmax_t	uinteger;
	char		*s;
	int			len;
	int			base;
	int			offset;

	uinteger = get_uinteger(format, va);
	if (format->specifier == 'u')
		base = 10;
	else
		base = format->specifier == 'o' ? 8 : 16;
	if ((len = uintmaxtoa(uinteger, &s, format, base)) < 0)
		return (-1);
	offset = (format->width > len ? format->width - len : 0);
	base = len + offset;
	if ((!(format->flags & 1) &&
	ft_printf_pad(1, format->flags & 16 ? '0' : ' ', offset) < offset) ||
	write(1, s, len) < len ||
	((format->flags & 1) && ft_printf_pad(1, ' ', offset) < offset))
		base = -1;
	free(s);
	return (base);
}
