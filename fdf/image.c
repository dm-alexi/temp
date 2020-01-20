/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:13:26 by sscarecr          #+#    #+#             */
/*   Updated: 2020/01/20 19:20:03 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

t_image		*new_image(void *mlx, int width, int height)
{
	t_image		*image;

	if (!(image = (t_image*)ft_memalloc(sizeof(t_image))) ||
	!(image->img = mlx_new_image(mlx, width, height)))
		sys_error();
	image->s = mlx_get_data_addr(image->img, &(image->bpp), &(image->width),
		&(image->endian));
	image->height = height;
	return (image);
}
