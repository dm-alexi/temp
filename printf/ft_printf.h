#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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

#endif
