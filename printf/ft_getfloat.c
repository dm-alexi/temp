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

#include <stdlib.h>
#include "ft_bigint.h"

static const int	g_pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000,
	10000000, 100000000};
/*
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
*/
void	ft_make_bigint(double value, t_bigint *res, int *exp10)
{
	uint64_t	val;
	t_bigint	pow;
	t_bigint	tmp;
	int			exp;

	val = *(uint64_t*)&value;
	exp = (int32_t)((val & 0x7ff0000000000000) >> 52) - 1075;
	val = (val & 0x000fffffffffffff);
	if (exp > -1075)
		val |= 0x0010000000000000;
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

//check rounding on unix
char	*ft_bigint2str(t_bigint *a)
{
	char		*s;
	int			j;
	int			i;
	uint32_t	t;

	if (!(s = (char*)malloc(9 * a->len)))
		return (NULL);
	i = a->len - 1;
	while (i >= 0)
	{
		t = a->arr[i--];
		j = 8;
		while (j > 0)
		{
			*s++ = t / g_pow10[j] + '0';
			t %= g_pow10[j--];
		}
		*s++ = t + '0';
	}
    return (s - 9 * a->len);
}
