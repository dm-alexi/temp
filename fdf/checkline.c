/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:21:33 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/02 11:28:15 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int     check_line(t_image *image, t_vertex *a, t_vertex *b)
{
	if ((a->x >= image->width && b->x >= image->width) || (a->x < 0 && b->x < 0)
	|| (a->y >= image->height && b->y >= image->height) ||
	(a->y < 0 && b->y < 0))
		return (0);
	return (1);
}