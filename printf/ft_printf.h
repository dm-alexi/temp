#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_conversion
{
    int		width;
    int		precision;
    char	flags[4];
    char	length[2];
    char	specifier;
}				t_conversion;

#endif
