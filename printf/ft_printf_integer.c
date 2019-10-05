/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:22:02 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/05 19:27:22 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

static unsigned int		maxintlen(intmax_t n)
{
	unsigned int		len;

	len = (n < 0);
	while (n && ++len)
		n /= 10;
	return (len);
}

static unsigned int		intmaxtoa(intmax_t n, char **s)
{
	unsigned int		len;
	unsigned int		tmp;

	if (!(len = maxintlen(n)))
	{
		*s = ft_strdup("0");
		return (1);
	}
	if (!(*s = (char*)malloc(len + 1)))
		return (0);
	tmp = len;
	(*s)[tmp] = '\0';
	if (n < 0)
	{
		(*s)[0] = '-';
		(*s)[--tmp] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (n)
	{
		(*s)[--tmp] = n % 10 + '0';
		n /= 10;
	}
	return (len);
}

void					ft_printf_integer(t_format *format, va_list *va, int *n)
{
	char			*s;
	intmax_t		integer;
	unsigned int	len;

	if (!format->length)
		integer = (int)va_arg(*va, int);
	else if (format->length == 1)
		integer = (char)va_arg(*va, int);
	else if (format->length == 'h')
		integer = (short)va_arg(*va, int);
	else if (format->length == 'l')
		integer = (long)va_arg(*va, long);
	else if (format->length == 2)
		integer = (long long)va_arg(*va, long long);
	else if (format->length == 'j')
		integer = (intmax_t)va_arg(*va, intmax_t);
	else if (format->length == 'z')
		integer = (ssize_t)va_arg(*va, ssize_t);
	else if (format->length == 't')
		integer = (ptrdiff_t)va_arg(*va, ptrdiff_t);
	len = intmaxtoa(integer, &s);
	*n += len;
	write(1, s, len);
	free(s);
}
