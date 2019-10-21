/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:46:55 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/21 23:37:25 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_bigint.h"
#include "ft_printf.h"

static const int	g_pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000,
	10000000, 100000000};

int			ft_bigint2str(t_bigint *a, int exp, char *s)
{
	int			len;
	char		*t;
	int			j;
	int			i;
	uint32_t	n;

	len = (a->len * 9 > -exp ? a->len * 9 : -exp) + 1;
	if (!(s = (char*)ft_memalloc(len)))
		return (-1);
	i = a->len - 1;
	t = s + 1 + (a->len * 9 > -exp ? 0 : -exp - a->len * 9);
	while (i >= 0)
	{
		n = a->arr[i--];
		j = 8;
		while (j > 0)
		{
			*t++ = n / g_pow10[j];
			n %= g_pow10[j--];
		}
		*t++ = n;
	}
	return (len);
}

static int	intlen(uint32_t n)
{
	int		i;

	i = 1;
	while (n >= g_pow10[i])
		++i;
	return (i);
}

int			ft_bigint2str_noexp(t_bigint *a, char **s)
{
	int			len;
	int			i;
	int			j;
	uint32_t	n;

	j = intlen(a->arr[a->len - 1]);
	len = (a->len - 1) * 9 + j;
	if (!(*s = (char*)ft_memalloc(len)))
		return (-1);
	i = a->len - 1;
	n = a->arr[i--];
	while (j >= 0)
	{
		*((*s)++) = n / g_pow10[j];
		n %= g_pow10[j--];
	}
	while (i >= 0 && (j = 8))
	{
		n = a->arr[i--];
		while (j >= 0)
		{
			*((*s)++) = n / g_pow10[j];
			n %= g_pow10[j--];
		}
	}
	*s -= len;
	return (len);
}

char		*ft_printf_b2f(t_format *format, t_bigint *t, int exp, int *sign)
{
	char	*str;
	char	*s;
	int		len;
	int		i;

	if ((len = ft_bigint2str_noexp(t, &str)) < 0)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] += '0';
	write(1, str, len);
	return (str);
}
