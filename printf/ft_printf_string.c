/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:15:06 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/27 17:52:04 by sscarecr         ###   ########.fr       */
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

int			ft_printf_char(t_format *format, va_list *va)
{
	unsigned char	c;
	int				offset;

	if (format->type == 'C' || format->length == 'l')
		return (ft_printf_wchar(format, va));
	c = (unsigned char)va_arg(*va, int);
	if (format->width <= 1)
		return (write(1, &c, 1) == 1 ? 1 : -1);
	offset = format->width - 1;
	if ((!format->rpad &&
	ft_printf_pad(1, format->fill, offset) < offset) ||
	write(1, &c, 1) < 1 ||
	(format->rpad && ft_printf_pad(1, format->fill, offset) < offset))
		return (-1);
	return (format->width);
}

int			ft_printf_string(t_format *format, va_list *va)
{
	char		*s;
	int			len;
	int			offset;

	if (format->type == 'S' || format->length == 'l')
		return (ft_printf_wstring(format, va));
	if (!(s = (char*)va_arg(*va, char*)))
		s = "(null)";
	len = ft_strlen(s);
	if (format->prec >= 0 && len > format->prec)
		len = format->prec;
	if (format->width <= len)
		return (write(1, s, len) == len ? len : -1);
	offset = format->width - len;
	if ((!format->rpad && ft_printf_pad(1, format->fill, offset) < offset) ||
	(write(1, s, len) < len) ||
	(format->rpad && ft_printf_pad(1, format->fill, offset) < offset))
		return (-1);
	return (format->width);
}

int			ft_printf_percent(t_format *format)
{
	int			offset;

	if (format->width <= 1)
		return (write(1, "%", 1) == 1 ? 1 : -1);
	offset = format->width - 1;
	if ((!format->rpad && ft_printf_pad(1, format->fill, offset) < offset) ||
	write(1, "%", 1) < 1 ||
	(format->rpad && ft_printf_pad(1, format->fill, offset) < offset))
		return (-1);
	return (format->width);
}
