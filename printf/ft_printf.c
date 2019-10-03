#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

void	set_flags(const char **s, t_format *format)
{
	format->flags = 0;
	while (**s == '-' || **s == '+' || **s == ' ' || **s == '#' || **s == '0')
	{
		if (**s == '-')
			format->flags |= 1;
		if (**s == '+')
			format->flags |= 2;
		if (**s == ' ')
			format->flags |= 4;
		if (**s == '#')
			format->flags |= 8;
		if (**s == '0')
			format->flags |= 16;
		++*s;
	}
}

void	set_wp(const char **s, t_format *format, va_list *va)
{
	//default values?
	if (ft_isdigit(**s))
		format->width = ft_strtol((char*)s, (char**)&s, 10);
	else if (**s == '*' && ++*s)
		format->width = va_arg(*va, int);
    if (**s == '.' && ++*s)
	{
		if (ft_isdigit(**s))
			format->precision = ft_strtol((char*)s, (char**)&s, 10);
		else if (**s == '*' && ++*s)
			format->precision = va_arg(*va, int);
	}
}

void	set_specifier(const char **s, t_format *format)
{
    format->length = 0;
    if (ft_strnequ(*s, "hh", 2) && (*s += 2))
		format->length = 1;
	else if (ft_strnequ(*s, "ll", 2) && (*s += 2))
		format->length = 2;
	else if (**s == 'h' || **s == 'l' || **s == 'j' || **s == 'z' || **s == 't'
	|| **s == 'L')
		format->length = *((*s)++);
	format->specifier = 0;
    if ((**s >= 'a' && **s <= 'g') || **s == 'i' || (**s >= 'n' && **s <= 'p')
	|| **s == 's' || **s == 'u' || **s == 'x' || **s == 'A' || **s == 'E' ||
	**s == 'F' || **s == 'G')
		format->specifier = *((*s)++);
}

void	set_format(const char **s, t_format *format, va_list *va)
{
	set_flags(s, format);
	set_wp(s, format, va);
	set_specifier(s, format);
}

void	print_formatted(const char **s, va_list *va, int *n)
{
	t_format	format;
	const char	*t;

	set_format(s, &format, va);
	if (!format.specifier)
	{
		t = *s - 1;
		while (*t != '%')
			--t;
		*n += *s - t;
		write(1, t, *s - t);
		return ;
	}
	//ft_putstr()
}

int		ft_printf(const char *line, ...)
{
	int				n;
	va_list			va;
	const char		*s;

	//if (!line)
	//	return (-1);
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
			print_formatted(&s, &va, &n);
		line = s;
	}
	va_end(va);
	return (n);
}
