/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:07:15 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/09 22:53:20 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGINT_H
#define FT_BIGINT_H

#include <stdint.h>
#define MAX_BLOCKS 1024

typedef struct	s_bigInt
{
	uint32_t	len;
	uint32_t	arr[MAX_BLOCKS];
}				t_bigInt;

void	bigint_sum(t_bigInt *res, const t_bigInt *a, const t_bigInt *b);
int		bigint_cmp(const t_bigInt *a, const t_bigInt *b);
void	bigint_mult_int(t_bigInt *res, const t_bigInt *a, const int32_t b);
void	bigint_mult(t_bigInt *res, const t_bigInt *a, const t_bigInt *b);
void    bigint_mult2(t_bigInt *res, const t_bigInt *a);
void	bigint_mult2_inplace(t_bigInt *res);
void	bigint_mult10(t_bigInt *res, const t_bigInt *a);

#endif
