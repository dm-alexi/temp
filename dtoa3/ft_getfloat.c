/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:37:41 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/12 21:04:48 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"

static const int	g_pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000,
	10000000};

void	get_double(double value, int *sign, uint64_t *frac, int *exp)
{
	uint64_t	val;

	val = *(uint64_t*)&value;
	*sign = (val & 0x8000000000000000L) != 0;
	*exp = (int32_t)((val & 0x7fffffffffffffff) >> 52) - 1075;
	*frac = (val & 0x000fffffffffffff) | 0x0010000000000000;
	while (!(*frac & 1L))
	{
		++*exp;
		*frac >>= 1;
	}
}

void	ft_make_bigint(double value, t_bigint *res, int *exp10)
{
	uint64_t	val;
	t_bigint	pow;
	t_bigint	tmp;
	int			exp;

	val = *(uint64_t*)&value;
	exp = (int32_t)((val & 0x7ff0000000000000) >> 52) - 1075;
	val = (val & 0x000fffffffffffff) | 0x0010000000000000;
	while (!(val & 1L))
	{
		++exp;
		val >>= 1;
	}
	*exp10 = 0;
	if (exp < 0)
	{
		*exp10 = exp;
		ft_bigint_pow5(&pow, -exp);
	}
	else
		ft_bigint_pow2(&pow, exp);
	ft_bigint_get(&tmp, val);
	ft_bigint_mult(res, &tmp, &pow);
}

static int	intlen(int n)
{
	int		i;

	i = 0;
	while (n)
	{
		++i;
		n /= 10;
	}
	return (i);
}

void	ft_bigint_round(char *s, t_bigint *res, int *exp10, int prec)
{
	int		i;
	int		j;
	int		k;
	int		len;

    i = 0;
    j = res->len - 1;
    k = intlen(res->arr[res->len - 1]);
    len = (res->len - 1) * 9 + k;
    while (i <= prec && j >= 0)
	{

	}
}
