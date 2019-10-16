/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:14:16 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/06 15:39:54 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

void	set_flags(const char **s, t_format *format)
{
	format->flags = 0;
	while (**s && ft_strchr("-+ #0\'", **s))
	{
		if (**s == '-')
			format->flags |= 1;
		else if (**s == '+')
			format->flags |= 2;
		else if (**s == ' ')
			format->flags |= 4;
		else if (**s == '#')
			format->flags |= 8;
		else if (**s == '0')
			format->flags |= 16;
		else if (**s == '\'')
			format->flags |= 32;
		++*s;
	}
}

void	set_wp(const char **s, t_format *format, va_list *va)
{
	format->width = 0;
	format->precision = -1;
	if (ft_isdigit(**s))
		format->width = ft_strtol((char*)*s, (char**)s, 10);
	else if (**s == '*' && ++*s)
		format->width = va_arg(*va, int);
	if (**s == '.' && ++*s)
	{
		format->precision = 0;
		if (ft_isdigit(**s))
			format->precision = ft_strtol((char*)*s, (char**)s, 10);
		else if (**s == '*' && ++*s)
			format->precision = va_arg(*va, int);
		if (format->precision < 0)
			format->precision = -format->precision;
	}
}

void	set_specifier(const char **s, t_format *format)
{
	format->length = 0;
	if (ft_strnequ(*s, "hh", 2) && (*s += 2))
		format->length = 'H';
	else if (ft_strnequ(*s, "ll", 2) && (*s += 2))
		format->length = 'L';
	else if (**s && ft_strchr("hljztL", **s))
		format->length = *((*s)++);
	format->specifier = 0;
	if (**s && ft_strchr("cdefginpsuxXEFG", **s))
		format->specifier = *((*s)++);
}

void	set_format(const char **s, t_format *format, va_list *va)
{
	set_flags(s, format);
	set_wp(s, format, va);
	set_specifier(s, format);
}

int		print_formatted(const char **s, va_list *va, int n)
{
	t_format	format;
	int			count;

	set_format(s, &format, va);
	if (!format.specifier)
		count = ft_printf_nospec(*s);
	else if (format.specifier == 'c')
		count = ft_printf_char(&format, va);
	else if (format.specifier == 's')
		count = ft_printf_string(&format, va);
	else if (format.specifier == 'd' || format.specifier == 'i')
		count = ft_printf_int(&format, va);
	else if (ft_strchr("uoxX", format.specifier))
		count = ft_printf_uint(&format, va);
	else if (format.specifier == 'p')
		count = ft_printf_ptr(&format, va);
	return (count);
}

int		ft_printf(const char *line, ...)
{
	int				n;
	va_list			va;
	const char		*s;

	n = 0;
	va_start(va, line);
	s = line;
	while (*line)
	{
		while (*s && *s != '%')
			++s;
		n += s - line;
		write(1, line, s - line);
		if (*s && *++s == '%' && ++n)
			write(1, s++, 1);
		else if (*s)
			print_formatted(&s, &va, n);
		line = s;
	}
	va_end(va);
	return (n);
}
