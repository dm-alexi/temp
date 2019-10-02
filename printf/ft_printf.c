#include <stdarg.h>
#include <stdlib.h>
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

	 set_format(s, &format, va);
}

int		ft_printf(const char *line, ...)
{
	int				n;
	va_list			va;

	//if (!line)
	//	return (-1);
	n = 0;
	va_start(va, line);
	while (*line)
	{
        if (*line == '%')
		{
			//offset = convert(format, &conv);
			++line;
			if (*line == '%')
			{
				ft_putchar('%');
				++n;
				++line;
			}
            else
				print_formatted(&line, &va, &n);
			//x = va_arg(va, int);
            //n += print_formatted(format, &conv);
            //format += offset;
            //ft_putnbr(x);
            //++format;
		}
		else
		{
			ft_putchar(*line++);
			++n;
		}
	}
	va_end(va);
	return (n);
}
