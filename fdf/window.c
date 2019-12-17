/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:19:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/17 20:05:05 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include "fdf.h"

void	fill_image(void *img)
{
	int		bpp;
	int		sl;
	int		endian;
	char 	*s;

	s = mlx_get_data_addr(img, &bpp, &sl, &endian);
	ft_printf("%d %d %d", bpp, sl, endian);
	s[100*bpp / 8 + 10 * sl] = 122;
	s[100*bpp / 8 + 10 * sl + 1] = 122;
	s[100*bpp / 8 + 10 * sl + 2] = 122;
	s[100*bpp / 8 + 10 * sl + 3] = 0;
}

void	window(char *file)
{
	void	*mlx;
	void	*win;
	t_image	*image;

	/*if (!(mlx = mlx_init()) || !(win = mlx_new_window(mlx, WIDTH, HEIGHT, file))
	|| !(img = mlx_new_image(mlx, WIDTH, HEIGHT)))
		sys_error();*/
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, file);
	image = new_image(mlx, WIDTH, HEIGHT);
	mlx_key_hook(win, &key_handle, NULL);
	//fill_image(img);
	t_dot a = {100, 100, 0xffffff}, b = {500, 400, 0xffffff}, c = {200, 600, 0xffffff}, d = {10, 400, 0xffffff};
	image_draw_line(image, &a, &b);
	image_draw_line(image, &b, &c);
	image_draw_line(image, &c, &d);
	image_draw_line(image, &d, &a);
	mlx_put_image_to_window(mlx, win, image->img, 0, 0);
	mlx_loop(mlx);
}
