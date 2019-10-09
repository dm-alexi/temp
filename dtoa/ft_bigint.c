/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:07:10 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/09 22:41:25 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"

int		bigint_cmp(const t_bigInt *a, const t_bigInt *b)
{
	int		i;

	if (a->len != b->len)
		return (a->len - b->len);
	i = a->len - 1;
	while (i >= 0)
	{
		if (a->arr[i] != b->arr[i])
			return (a->arr[i] - b->arr[i]);
		++i;
	}
	return (0);
}

void	bigint_sum(t_bigInt *res, const t_bigInt *a, const t_bigInt *b)
{
	uint64_t	carry;
	uint64_t	sum;
	int			i;

	if (a->len < b->len)
		bigint_sum(res, b, a);
	else
	{
		carry = 0;
		i = 0;
		while (i < b->len)
		{
			sum = carry + (uint64_t)a->arr[i] + (uint64_t)b->arr[i];
			res->arr[i++] = (uint32_t)sum;
			carry = sum >> 32;
		}
		while (i < a->len)
		{
			sum = carry + (uint64_t)a->arr[i];
			res->arr[i++] = (uint32_t)sum;
			carry = sum >> 32;
		}
		res->arr[i] = carry;
		res->len = carry ? i + 1 : i;
	}
}
