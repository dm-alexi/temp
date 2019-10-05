/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:15:06 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/05 20:39:27 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_printf_strfill(int fd, char c, int n)
{
	while (n-- > 0)
		write(fd, &c, 1);
}

void	ft_printf_char(t_format *format, va_list *va, int *n)
{
	char		c;
	wchar_t		wc;
	int			offset;
	int			len;

	if (format->length == 'l')
		wc = (wchar_t)va_arg(*va, wchar_t);
	else
		c = (char)va_arg(*va, int);
	offset = (format->width > 1 ? format->width - 1 : 0);
	len = format->length == 'l' ? sizeof(wchar_t) : 1;
	if (!(format->flags & 1))
		ft_printf_strfill(1, ' ', offset);
	write(1, format->length == 'l' ? (char*)&wc : &c, len);
	if ((format->flags & 1))
		ft_printf_strfill(1, ' ', offset);
	*n += offset + 1;
}

void	ft_printf_string(t_format *format, va_list *va, int *n)
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
	offset = (format->width > len ? format->width - len : 0);
	if (!(format->flags & 1))
		ft_printf_strfill(1, ' ', offset);
	if (format->length == 'l')
		write(1, ws, len * sizeof(wchar_t));
	else
		write(1, s, len);
	if ((format->flags & 1))
		ft_printf_strfill(1, ' ', offset);
	*n += offset + len;
}
