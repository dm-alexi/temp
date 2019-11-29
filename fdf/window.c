/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:19:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/29 21:04:15 by sscarecr         ###   ########.fr       */
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
	void	*img;

	//if (!(mlx = mlx_init()) || !(win = mlx_new_window(mlx, WIDTH, HEIGHT, file)))
	//!(img = mlx_new_image(mlx, WIDTH, HEIGHT)))
	//	sys_error();
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, file);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	/*for (int i = 0; i < 100; ++i)
		mlx_pixel_put(mlx, win, i, 100, 250);*/
	mlx_key_hook(win, &key_handle, NULL);
	fill_image(img);
	//t_point a = {100, 100, 0}, b = {500, 100, 0};
	//image_draw_line(img, &a, &b, 250);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}
