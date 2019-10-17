/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:21:27 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/16 20:00:17 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	len = format->precision < (int)sizeof(void*) ? (int)sizeof(void*) :
		format->precision;
	if (!(s = (char*)malloc(len)))
		return (-1);
	tmp = len;
	while (tmp)
	{
		s[--tmp] = p % 16 < 10 ? p % 16 + '0' : p % 16 - 10 + 'a';
		p /= 16;
	}
	offset = (format->width > len ? format->width - len : 0);
	tmp = len + offset;
	if ((!(format->flags & 1) && ft_printf_pad(1, ' ', offset) < offset) ||
	write(1, s, len) < len ||
	((format->flags & 1) && ft_printf_pad(1, ' ', offset) < offset))
		tmp = -1;
	free(s);
	return (tmp);
}
