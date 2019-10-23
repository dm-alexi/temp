/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:37:41 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/23 20:10:04 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigint.h"

/*
** Makes t_bigint from val; returns -exp10 (positive!)
*/

int		ft_make_bigint(t_bigint *res, int exp, uint64_t val)
{
	t_bigint	pow;
	t_bigint	tmp;

	while (!(val & 1L))
	{
		++exp;
		val >>= 1;
	}
	if (exp < 0)
		ft_bigint_pow5(&pow, -exp);
	else
		ft_bigint_pow2(&pow, exp);
	ft_bigint_get(&tmp, val);
	ft_bigint_mult(res, &tmp, &pow);
	return (exp < 0 ? -exp : 0);
}
