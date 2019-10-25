/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:14:16 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/25 23:13:38 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	set_flags(const char **s, t_format *format)
{
	ft_bzero(format, sizeof(t_format));
	while (**s && ft_strchr("-+ #0\'", **s))
	{
		if (**s == '-')
			format->rpad = 1;
		else if (**s == '+')
			format->sign = '+';
		else if (**s == ' ' && !format->sign)
			format->sign = ' ';
		else if (**s == '#')
			format->sharp = 1;
		else if (**s == '0')
			format->fill = '0';
		else if (**s == '\'')
			format->apost = 1;
		++*s;
	}
}

void	set_wp(const char **s, t_format *format, va_list *va)
{
	format->prec = -1;
	if (ft_isdigit(**s))
		format->width = ft_strtol((char*)*s, (char**)s, 10);
	else if (**s == '*' && ++*s)
		format->width = va_arg(*va, int);
	if (ft_isdigit(**s))
		format->width = ft_strtol((char*)*s, (char**)s, 10);
	if (format->width < 0)
	{
		format->width = -format->width;
		format->rpad = 1;
	}
	if (**s == '.' && ++*s)
	{
		format->prec = 0;
		if (ft_isdigit(**s))
			format->prec = ft_strtol((char*)*s, (char**)s, 10);
		else if (**s == '*' && ++*s)
			format->prec = va_arg(*va, int);
		//check is this is still necessary
		if (format->prec < 0)
			format->prec = -1;
	}
	if (format->rpad || !format->fill)
		format->fill = ' ';
}

void	set_specifier(const char **s, t_format *format)
{
	if (ft_strnequ(*s, "hh", 2) && (*s += 2))
		format->length = 'H';
	else if (ft_strnequ(*s, "ll", 2) && (*s += 2))
		format->length = 'L';
	else if (**s && ft_strchr("hljztL", **s))
		format->length = *((*s)++);
	if (**s && ft_strchr("cdefginoprsuxEFGX%", **s))
		format->type = *((*s)++);
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

	set_format(s, &format, va);
	if (!format.type)
		return (0);
	if (format.type == '%')
		return (ft_printf_percent(&format));
	if (format.type == 'c' || format.type == 'C')
		return (ft_printf_char(&format, va));
	if (format.type == 's' || format.type == 'S')
		return (ft_printf_string(&format, va));
	if (format.type == 'd' || format.type == 'i')
		return (ft_printf_int(&format, va));
	if (ft_strchr("uoxX", format.type))
		return (ft_printf_uint(&format, va));
	if (format.type == 'p')
		return (ft_printf_ptr(&format, va));
	if (ft_strchr("efgEFG", format.type))
		return (ft_printf_float(&format, va));
	if (format.type == 'r')
		return (ft_printf_r(&format, va));
	if (format.type == 'n')
		return (ft_printf_n(va, n));
	return (0);
}

int		ft_printf(const char *line, ...)
{
	int				n;
	int				count;
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
		if (*s)
		{
			++s;
			if ((count = print_formatted(&s, &va, n)) < 0)
				return (-1);
			n += count;
		}
		line = s;
	}
	va_end(va);
	return (n);
}
