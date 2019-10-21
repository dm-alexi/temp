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

void	ft_make_bigint(t_bigint *res, int exp, uint64_t	val, int *exp10)
{
	t_bigint	pow;
	t_bigint	tmp;

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
