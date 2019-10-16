/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:15:06 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/16 23:03:34 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int				ft_printf_strfill(int fd, char c, int n)
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

int				ft_printf_char(t_format *format, va_list *va)
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
	if ((!(format->flags & 1) &&
	ft_printf_strfill(1, format->flags & 16 ? '0' : ' ', offset) < offset) ||
	write(1, format->length == 'l' ? (char*)&wc : &c, len) < len ||
	((format->flags & 1) && ft_printf_strfill(1, ' ', offset) < offset))
		return (-1);
	return (offset + 1);
}

static int		ft_printf_lstring(t_format *format, va_list *va)
{
	wchar_t		*ws;
	int			len;
	int			offset;

	if (!(ws = (wchar_t*)va_arg(*va, wchar_t*)))
		ws = L"(null)";
	len = ft_wcslen(ws);
	if (format->precision >= 0 && len > format->precision)
		len = format->precision;
	offset = (format->width > len ? format->width - len : 0);
	if ((!(format->flags & 1) &&
	ft_printf_strfill(1, format->flags & 16 ? '0' : ' ', offset) < offset) ||
	(write(1, ws, len * sizeof(wchar_t)) < len * sizeof(wchar_t)) ||
	((format->flags & 1) && ft_printf_strfill(1, ' ', offset) < offset))
		return (-1);
	return (offset + len);
}

int				ft_printf_string(t_format *format, va_list *va)
{
	char		*s;
	int			len;
	int			offset;

	if (format->length == 'l')
		return (ft_printf_lstring(format, va));
	if (!(s = (char*)va_arg(*va, char*)))
		s = "(null)";
	len = ft_strlen(s);
	if (format->precision >= 0 && len > format->precision)
		len = format->precision;
	offset = (format->width > len ? format->width - len : 0);
	if ((!(format->flags & 1) &&
	ft_printf_strfill(1, format->flags & 16 ? '0' : ' ', offset) < offset) ||
	(write(1, s, len) < len) ||
	((format->flags & 1) && ft_printf_strfill(1, ' ', offset) < offset))
		return (-1);
	return (offset + len);
}

int		ft_printf_percent(t_format *format)
{
	int			offset;

	offset = format->width > 1 ? format->width - 1 : 0;
	if ((!(format->flags & 1) &&
	ft_printf_strfill(1, format->flags & 16 ? '0' : ' ', offset) < offset) ||
	write(1, "%", 1) < 1 ||
	((format->flags & 1) && ft_printf_strfill(1, ' ', offset) < offset))
		return (-1);
	return (offset + 1);
}
