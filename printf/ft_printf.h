#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_format
{
    int		width;
    int		precision;
    char	flags;
    char	length;
    char	specifier;
}				t_format;

int				ft_printf(const char *format, ...);
void			ft_printf_string(t_format *format, va_list *va, int *n);
void			ft_printf_char(t_format *format, va_list *va, int *n);

#endif
