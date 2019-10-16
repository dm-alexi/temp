/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:15:06 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/08 19:45:35 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_printf_strfill(int fd, char c, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (write(fd, &c, 1) < 1)
			return (i);
		++i;
	}
	return (n);
}

int		ft_printf_char(t_format *format, va_list *va)
{
	char		c;
	wchar_t		wc;
	int			offset;
	int			len;

	if (format->length == 'l')
		wc = (wchar_t)va_arg(*va, int);
	else
		c = (char)va_arg(*va, int);
	offset = (format->width > 1 ? format->width - 1 : 0);
	len = format->length == 'l' ? sizeof(wchar_t) : 1;
	if ((!(format->flags & 1) && ft_printf_strfill(1, ' ', offset) < offset) ||
	write(1, format->length == 'l' ? (char*)&wc : &c, len) < len ||
	((format->flags & 1) && ft_printf_strfill(1, ' ', offset) < offset))
		return (-1);
	return (offset + 1);
}

int		ft_printf_string(t_format *format, va_list *va)
{
	char		*s;
	wchar_t		*ws;
	int			len;
	int			offset;

	if (format->length == 'l')
		ws = (wchar_t*)va_arg(*va, wchar_t*);
	else
		s = (char*)va_arg(*va, char*);
	len = format->length == 'l' ? ft_wcslen(ws) : ft_strlen(s);
	if (len > format->precision)
		len = format->precision;
	offset = (format->width > len ? format->width - len : 0);
	if (!(format->flags & 1) && ft_printf_strfill(1, ' ', offset) < offset)
		return (-1);
	if (format->length == 'l' &&
	write(1, ws, len * sizeof(wchar_t)) < len * sizeof(wchar_t))
		return (-1);
	if (format->length != 'l' && write(1, s, len) < len)
		return (-1);
	if ((format->flags & 1) && ft_printf_strfill(1, ' ', offset) < offset)
		return (-1);
	return (offset + len);
}

int		ft_printf_nospec(const char *s)
{
	const char	*t;
	int			n;

	t = s - 1;
	while (*t != '%')
		--t;
	n = s - t;
	if (write(1, t, n) < n)
		return (-1);
	return (n);
}
