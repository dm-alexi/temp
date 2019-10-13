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
	exp = (int32_t)((val & 0x7fffffffffffffff) >> 52) - 1075;
	val = (val & 0x000fffffffffffff) | 0x0010000000000000;
	/*
	while (!(val & 1L))
	{
		++exp;
		val >>= 1;
	}*/
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

void	ft_get_prev(double value, t_bigint *res, int *exp10)
{
	uint64_t	val;
	t_bigint	pow;
	t_bigint	tmp;
	int			exp;

	val = *(uint64_t*)&value;
	exp = (int32_t)((val & 0x7fffffffffffffff) >> 52) - 1075;
	val = (val & 0x000fffffffffffff) | 0x0010000000000000;
	--val;
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

void	ft_get_next(double value, t_bigint *res, int *exp10)
{
	uint64_t	val;
	t_bigint	pow;
	t_bigint	tmp;
	int			exp;

	val = *(uint64_t*)&value;
	exp = (int32_t)((val & 0x7fffffffffffffff) >> 52) - 1075;
	val = (val & 0x000fffffffffffff) | 0x0010000000000000;
	++val;
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

void	get_margins(double value, t_bigint *lm, t_bigint *hm, int *expm)
{
	uint64_t	val;
	int			exp;

	val = *(uint64_t*)&value;
	exp = (int32_t)((val & 0x7fffffffffffffff) >> 52) - 1076;
	if (exp > 0)
	{
		*expm = 0;
		ft_bigint_pow2(lm, exp);
		ft_bigint_pow2(hm, exp + ((val & 0x000fffffffffffff)
		== 0x000fffffffffffff));
	}
	else
	{
		*expm = exp - ((val & 0x000fffffffffffff) == 0x000fffffffffffff);
		ft_bigint_pow5(lm, -exp);
		ft_bigint_pow5(hm, -*expm);
	}
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

void	ft_bigint_round(t_bigint *res, int *rexp, t_bigint *margin, int mexp)
{
	t_bigint	tmp;
	int			i;
	int			n;
	uint32_t	carry;
	while (mexp < *rexp)
	{
		ft_bigint_mult_int(&tmp, res, 10);
		--*rexp;
		ft_bigint_copy(res, &tmp);
	}
	i = 0;
	while (i < margin->len - 1)
		res->arr[i++] = 0;
	n = intlen(margin->arr[margin->len - 1]);
	res->arr[i] -= res->arr[i] % g_pow10[n - 1];
	if (res->arr[i] / g_pow10[n - 1] % 10 < 5)
		res->arr[i] -= res->arr[i] % 10;
	else
	{
		res->arr[i] -= res->arr[i] % g_pow10[n];
		res->arr[i] += g_pow10[n];
		while ((carry = res->arr[i] / 1000000000) && i < res->len)
		{
			res->arr[i++] %= 1000000000;
			res->arr[i] += 1;
		}
		res->arr[i++] %= 1000000000;
		if (carry)
		{
			res->arr[i] = carry;
			res->len++;
		}
	}
}
