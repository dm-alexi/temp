/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:46:22 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/27 17:49:53 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

/*
void printbin(void *p, int n);

void	pw()
{
	wchar_t		c = 0x00e282ac;
	int n;
	char s[4] = {0};
	printbin(&c, 1);
	n = write(1, "\xe2\x82\xac", 3);
	printf("\n%d\n", n);
	n = printf("\xe2\x82\xac");
	printf("\n%d\n", n);
	s[0] = c & 0x000000ff;
	s[1] = (c & 0x0000ff00) >> 8;
	s[2] = (c & 0x00ff0000) >> 16;
	s[3] = (c & 0xff000000) >> 24;
	//write(1, s, 3);
	printbin("\xe2\x82\xac", 1);
	printf("---\n");
	printbin(s, 1);
}
*/

int			wchar2utf8(char *str, const wchar_t c)
{
	if (c <= 0x7f)
		return ((str[0] = c) || 1);
	if (c <= 0x7ff)
	{
		str[0] = 0xc0 | (c >> 6);
		str[1] = 0x80 | (c & 0x3f);
		return (2);
	}
	if (c <= 0xffff)
	{
		str[0] = 0xe0 | (c >> 12);
		str[1] = 0x80 | ((c >> 6) & 0x3f);
		str[2] = 0x80 | (c & 0x3f);
		return (3);
	}
	if (c <= 0x10ffff)
	{
		str[0] = 0xf0 | (c >> 18);
		str[1] = 0x80 | ((c >> 12) & 0x3f);
		str[2] = 0x80 | ((c >> 6) & 0x3f);
		str[3] = 0x80 | (c & 0x3f);
		return (4);
	}
	return (0);
}

int			ft_printf_wchar(t_format *format, va_list *va)
{
	wchar_t		c;
	char		str[4];
	int			n;
	int			offset;

	c = (wchar_t)va_arg(*va, int);
	n = wchar2utf8(str, c);
	if (format->width <= n)
		return (write(1, str, n) == n ? n : -1);
	offset = format->width - n;
	if ((!format->rpad &&
	ft_printf_pad(1, format->fill, offset) < offset) ||
	write(1, str, n) < n ||
	(format->rpad && ft_printf_pad(1, format->fill, offset) < offset))
		return (-1);
	return (offset + n);
}

int			ft_printf_wstring(t_format *format, va_list *va)
{
	wchar_t		*s;
	char		*str;
	int			n;
	int			tmp;

	n = 6;
	if (!(s = (wchar_t*)va_arg(*va, wchar_t*)))
		str = "(null)";
	else
	{
		if (!(str = (char*)malloc(ft_wcslen(s) * 4)))
			return (-1);
		n = 0;
		while (*s && (n + (tmp = wchar2utf8(str + n, *s++))) <= format->prec)
			n += tmp;
	}
	if ((tmp = format->width - n) <= 0)
		return (write(1, str, n) == n ? n : -1);
	if ((!format->rpad && ft_printf_pad(1, format->fill, tmp) < tmp) ||
	write(1, str, n) < n ||
	(format->rpad && ft_printf_pad(1, format->fill, tmp) < tmp))
		return (-1);
	return (format->width);
}
