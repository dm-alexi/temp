#include <stdarg.h>

int		ft_printf_n(va_list *va, int n)
{
	*((int*)va_arg(*va, int*)) = n;
	return (0);
}
