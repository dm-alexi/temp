/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:48:33 by sscarecr          #+#    #+#             */
/*   Updated: 2020/10/26 11:53:40 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex		complex_add(t_complex a, t_complex b)
{
	return (t_complex){.re = a.re + b.re, .im = a.im + b.im};
}

t_complex		complex_mul(t_complex a, t_complex b)
{
	return (t_complex){.re = a.re * b.re - a.im * b.im,
		.im = a.re * b.im + a.im * b.re};
}
