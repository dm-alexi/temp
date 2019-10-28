/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:14:16 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/27 20:53:47 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		print_formatted(const char **s, va_list *va, int n)
{
	t_format	format;

	ft_setformat(s, &format, va);
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
	if (ft_strchr("buoxX", format.type))
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
