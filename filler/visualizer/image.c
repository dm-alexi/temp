/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:13:26 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/17 19:23:36 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

t_image		*new_image(void *mlx, int width, int height)
{
	t_image		*image;

	if (!(image = (t_image*)ft_memalloc(sizeof(t_image))) ||
	!(image->img = mlx_new_image(mlx, width, height)))
		sys_error();
	image->map = mlx_get_data_addr(image->img, &(image->bpp),
		&(image->sizeline), &(image->endian));
	image->height = height;
	image->width = width;
	return (image);
}
