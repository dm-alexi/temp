#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int				n;
	int				offset;
	t_conversion	conv;
	va_list			va;

	if (!format)
		return (-1);
	n = 0;
	va_start(va, format);
	while (*format)
	{
        if(*format == '%')
		{
			offset = convert(format, &conv);
            //x = va_arg(va, type);
            n += print_formatted(format, &conv);
            format += offset;
		}
		else
		{
			ft_putchar(*format);
			++n;
		}
	}
	va_end(va);
	return (n);
}
