#include <unistd.h>
#include "ft_printf.h"

void	ft_printf_strfill(int fd, char c, int n)
{
	while (n-- > 0)
		write(fd, &c, 1);
}

void	ft_printf_char(t_format *format, va_list *va, int *n)
{
	char	c;
	int		offset;

	c = (char)va_arg(*va, int);
	offset = (format->width > 1 ? format->width - 1 : 0);
    if (!(format->flags & 1))
		ft_printf_strfill(1, ' ', offset);
	write(1, &c, 1);
	if ((format->flags & 1))
		ft_printf_strfill(1, ' ', offset);
	*n += offset + 1;
}

void	ft_printf_string(t_format *format, va_list *va, int *n)
{
	char	*s;
	int		len;
	int		offset;

	s = va_arg(*va, char*);
	len = ft_strlen(s);
	offset = (format->width > len ? format->width - len : 0);
	if (!(format->flags & 1))
		ft_printf_strfill(1, ' ', offset);
	write(1, s, len);
	if ((format->flags & 1))
		ft_printf_strfill(1, ' ', offset);
	*n += offset + len;
}
