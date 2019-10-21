/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:15:06 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/21 18:49:17 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int			ft_printf_pad(int fd, char c, int n)
{
	char	*s;
	int		i;

	if (!(s = (char*)malloc(n)))
	{
		i = 0;
		while (i < n)
		{
			if (write(fd, &c, 1) < 1)
				return (i);
			++i;
		}
		return (n);
	}
	ft_memset(s, c, n);
	i = write(fd, s, n);
	free(s);
	return (i);
}

//handle C and lc
int				ft_printf_char(t_format *format, va_list *va)
{
	unsigned char	c;
	int				offset;

/*	if (format->length == 'l' || format->type == 'C')
		return (ft_printf_wchar(format, va);*/
	c = (unsigned char)va_arg(*va, int);
	if (format->width <= 1)
		return (write(1, &c, 1) == 1 ? 1 : -1);
	offset = format->width - 1;
	if ((!format->minus &&
	ft_printf_pad(1, format->zero ? '0' : ' ', offset) < offset) ||
	write(1, &c, 1) < 1 ||
	(format->minus && ft_printf_pad(1, ' ', offset) < offset))
		return (-1);
	return (offset + 1);
}

//check it
static int		ft_printf_wstring(t_format *format, va_list *va)
{
	wchar_t		*ws;
	int			len;
	int			offset;

	if (!(ws = (wchar_t*)va_arg(*va, wchar_t*)))
		ws = L"(null)";
	len = ft_wcslen(ws);
	if (format->prec >= 0 && len > format->prec)
		len = format->prec;
	offset = (format->width > len ? format->width - len : 0);
	if ((!format->minus &&
	ft_printf_pad(1, format->zero ? '0' : ' ', offset) < offset) ||
	(write(1, ws, len * sizeof(wchar_t)) < len * sizeof(wchar_t)) ||
	(format->minus && ft_printf_pad(1, ' ', offset) < offset))
		return (-1);
	return (offset + len);
}

int				ft_printf_string(t_format *format, va_list *va)
{
	char		*s;
	int			len;
	int			offset;

/*
	if (format->length == 'l' || format->type == 'S')
		return (ft_printf_wstring(format, va));*/
	if (!(s = (char*)va_arg(*va, char*)))
		s = "(null)";
	len = ft_strlen(s);
	if (format->prec >= 0 && len > format->prec)
		len = format->prec;
	if (format->width <= len)
		return (write(1, s, len) == len ? len : -1);
	offset = format->width - len;
	if ((!format->minus &&
	ft_printf_pad(1, format->zero ? '0' : ' ', offset) < offset) ||
	(write(1, s, len) < len) ||
	(format->minus && ft_printf_pad(1, ' ', offset) < offset))
		return (-1);
	return (offset + len);
}

int		ft_printf_percent(t_format *format)
{
	int			offset;

	if (format->width <= 1)
		return (write(1, "%", 1) == 1 ? 1 : -1);
	offset = format->width - 1;
	if ((!format->minus &&
	ft_printf_pad(1, format->zero ? '0' : ' ', offset) < offset) ||
	write(1, "%", 1) < 1 ||
	(format->minus && ft_printf_pad(1, ' ', offset) < offset))
		return (-1);
	return (offset + 1);
}
