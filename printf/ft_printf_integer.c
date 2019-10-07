/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:22:02 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/06 15:39:04 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

static unsigned int		maxintlen(intmax_t n, t_format *format)
{
	unsigned int		len;

	len = (n < 0) || format->flags & 6;
	if (!n)
		++len;
	while (n && ++len)
		n /= 10;
	return (len);
}

static unsigned int		intmaxtoa(intmax_t n, char **s, t_format *format)
{
	unsigned int		len;
	unsigned int		tmp;

	len = maxintlen(n, format);
	if (!(*s = (char*)malloc(len + 1)))
		return (0);
	tmp = len;
	(*s)[tmp] = '\0';
	if (!n)
		(*s)[((format->flags & 6) > 0)] = '0';
	if (n < 0 && ((*s)[0] = '-'))
	{
		(*s)[--tmp] = -(n % 10) + '0';
		n = -(n / 10);
	}
	else if (format->flags & 6)
		(*s)[0] = format->flags & 2 ? '+' : ' ';
	while (n)
	{
		(*s)[--tmp] = n % 10 + '0';
		n /= 10;
	}
	return (len);
}

static intmax_t			get_integer(t_format *format, va_list *va)
{
	//handle L (int64_t ?)
	if (!format->length)
		return ((int)va_arg(*va, int));
	if (format->length == 1)
		return ((char)va_arg(*va, int));
	if (format->length == 'h')
		return ((short)va_arg(*va, int));
	if (format->length == 'l')
		return ((long)va_arg(*va, long));
	if (format->length == 2)
		return ((long long)va_arg(*va, long long));
	if (format->length == 'j')
		return ((intmax_t)va_arg(*va, intmax_t));
	if (format->length == 'z')
		return ((ssize_t)va_arg(*va, ssize_t));
	if (format->length == 't')
		return ((ptrdiff_t)va_arg(*va, ptrdiff_t));
	return ((int)va_arg(*va, int));
}

void					ft_printf_int(t_format *format, va_list *va, int *n)
{
	char			*s;
	intmax_t		integer;
	unsigned int	len;
	unsigned int	offset;

	integer = get_integer(format, va);
	len = intmaxtoa(integer, &s, format);
	offset = (format->width > len ? format->width - len : 0);
	if (!(format->flags & 1))
		ft_printf_strfill(1, format->flags & 16 ? '0' : ' ', offset);
	write(1, s, len);
	if (format->flags & 1)
		ft_printf_strfill(1, ' ', offset);
	free(s);
	*n += offset + len;
}
