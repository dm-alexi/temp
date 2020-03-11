/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:28:09 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/11 23:00:44 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "visual.h"

t_image	*new_image(void *mlx, int width, int height)
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

void	*init(int height, int width, char *title)
{
	t_screen	*s;

	if (!(s = (t_screen*)malloc(sizeof(t_screen))) ||
	!(s->mlx = mlx_init()) ||
	!(s->win = mlx_new_window(s->mlx, width, height, title)) ||
	!(s->image = new_image(s->mlx, width, height)))
		sys_error();
	return (s);
}
