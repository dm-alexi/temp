/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:22:02 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/06 15:39:04 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_bigint.h"
#include "libft/libft.h"

static int	ft_printf_zero(t_format *format, char sign, char **s)
{
    int		len;
    int		tmp;

    len = 1 + (sign > 0) + format->precision +
		(format->precision != 0 || (format->flags & 8));
    if (!(format->flags & 1) && len < format->width)
		len = format->width;
    if (!(*s = (char*)malloc(len)))
		return (-1);
	ft_memset(s, (format->flags & 16) ? '0' : ' ', len);
	tmp = len;
	while (format->precision > 0)
	{
		(*s)[--tmp] = '0';
		--format->precision;
	}
	if (tmp < len || format->flags & 8)
		(*s)[--tmp] == '.';
	s[--tmp] == '0';
    if (sign)
		(*s)[**s == '0' ? 0 : tmp - 1] = sign;
	return (len);
}


int		ft_printf_float(t_format *format, va_list *va)
{
    double	d;
    char	*s;
    char	sign;
    int		len;
    int		offset;

	//fix it with long double
	d = (double)va_arg(*va, double);
	if ((format->flags & 16) && format->precision >= 0)
		format->flags &= ~16;
	if (format->precision < 0)
		format->precision = 6;
	sign = 0;
	//get sign
	//check NaN Inf zero

	return (0);
}
