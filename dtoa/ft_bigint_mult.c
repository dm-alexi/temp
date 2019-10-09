/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:07:02 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/09 23:04:16 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"
#include "libft.h"

void	bigint_mult_int(t_bigInt *res, const t_bigInt *a, const int32_t b)
{
	uint32_t	carry;
	uint64_t	product;
	int			i;

	i = 0;
	carry = 0;
	while (i < a->len)
	{
		product = (int64_t)a->arr[i] * b + carry;
		res->arr[i++] = (uint32_t)product;
		carry = product >> 32;
	}
	if (carry)
	{
		res->arr[i] = carry;
		res->len = i + 1;
	}
	else
		res->len = i;
}

void	bigint_mult(t_bigInt *res, const t_bigInt *a, const t_bigInt *b)
{
	int			i;
	t_bigInt	tmp;

	if (a->len > b->len)
		bigint_mult(res, b, a);
	else
	{
		i = 0;
		ft_bzero(res->arr, 4 * MAX_BLOCKS);
		while (i < a->len)
		{
			if (a->arr[i])
			{
				bigint_mult_int(&tmp, b, a->arr[i]);
				ft_memmove(&tmp.arr + i, &tmp.arr, tmp.len * 4);
				ft_bzero(&tmp, i * 4);
				tmp.len += i;
				bigint_sum(res, res, &tmp);
			}
			++i;
		}
	}
}
