/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:19:30 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/21 22:42:02 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "ft_bigint.h"
# include "libft/libft.h"

typedef struct	s_format
{
	int		width;
	int		prec;
	char	length;
	char	type;
	char	sign;
	char	rpad;
	char	sharp;
	char	fill;
	char	apost;
}				t_format;

int				ft_printf(const char *format, ...);
int				ft_printf_pad(int fd, char c, int n);
int				ft_printf_percent(t_format *format);
int				ft_printf_string(t_format *format, va_list *va);
int				ft_printf_char(t_format *format, va_list *va);
int				ft_printf_int(t_format *format, va_list *va);
int				ft_printf_uint(t_format *format, va_list *va);
int				ft_printf_ptr(t_format *format, va_list *va);
int				ft_printf_float(t_format *format, va_list *va);
//int				ft_printf_f(t_format *format, t_bigint *t, int exp, char **s);
//int				ft_printf_e(t_format *format, t_bigint *t, int exp, char **s);
void			printbin(void *p, int n);
int				dtoa(double value, char *s, int prec);
int				ft_printf_efg(t_format *format, t_bigint *t, int exp, char **s);

#endif
