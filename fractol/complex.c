/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:55:37 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/18 20:14:19 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** square_dist returns square distance, avoiding sqrt() call here
*/

double	square_dist(t_complex *z, t_complex c)
{
	double	t;

	t = z->re * z->re - z->im * z->im + c.re;
	z->im = 2 * z->re * z->im + c.im;
	z->re = t;
	return (z->re * z->re + z->im * z->im);
}
