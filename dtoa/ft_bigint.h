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
#define MAX_BLOCKS 35

typedef struct	s_bigInt
{
	uint32_t	len;
	uint32_t	arr[MAX_BLOCKS];
}				t_bigInt;

void	bigint_sum(t_bigInt *res, const t_bigInt *a, const t_bigInt *b);

#endif
