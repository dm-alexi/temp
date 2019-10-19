/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:21:27 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/19 22:03:17 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

static int		ptrlen(uintptr_t p, char **s, t_format *format)
{
	int		len;

	len = 2 + (!p && format->precision);
	while (p && ++len)
		p /= 16;
	if (len < format->precision)
		len = format->precision;
	if (format->precision < len)
		format->precision = len;
	if (!(format->flags & 1) && len < format->width)
		len = format->width;
	if (!(*s = (char*)malloc(len)))
		return (-1);
	ft_memset(*s, ((format->flags & 16) ? '0' : ' '), len);
	return (len);
}

int				ft_printf_ptr(t_format *format, va_list *va)
{
	uintptr_t	p;
	int			len;
	int			tmp;
	int			offset;
	char		*s;

	p = (uintptr_t)va_arg(*va, void*);
	if ((len = ptrlen(p, &s, format)) < 0)
		return (-1);
	tmp = len;
	while (p || format->precision > 0)
	{
		s[--tmp] = p % 16 < 10 ? p % 16 + '0' : p % 16 - 10 + 'a';
		p /= 16;
		--format->precision;
	}
	s[*s == '0' ? 1 : tmp + 1] = 'x';
	offset = (format->width > len ? format->width - len : 0);
	tmp = len + offset;
	if (write(1, s, len) < len ||
	((format->flags & 1) && ft_printf_pad(1, ' ', offset) < offset))
		tmp = -1;
	free(s);
	return (tmp);
}
