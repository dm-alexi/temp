#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

int		ft_printf_ptr(t_format *format, va_list *va)
{
	uintptr_t	p;
	int			len;
	int			tmp;
	int			offset;
	char		*s;

	p = (uintptr_t)va_arg(*va, void*);
	len = format->precision < sizeof(void*) ? sizeof(void*) : format->precision; //fix here, unsigned vs signed
	if (!(s = (char*)malloc(len)))
		return (-1);
    tmp = len;
    while (tmp)
	{
		offset = p % 16;
		s[--tmp] = offset < 10 ? offset + '0' : offset - 10 + 'a';
		p /= 16;
	}
	offset = (format->width > len ? format->width - len : 0);
	tmp = len + offset;
	if ((!(format->flags & 1) && ft_printf_strfill(1, ' ', offset) < offset) ||
	write(1, s, len) < len ||
	((format->flags & 1) && ft_printf_strfill(1, ' ', offset) < offset))
		tmp = -1;
	free(s);
	return (tmp);
}

