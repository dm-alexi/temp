#include "fractol.h"


void		color_init(t_point cur, int iter, t_fractol *fractol)
{
	double	t;
	int		i;
	t_argb	color;

	t = (double)iter / fractol->a.max_iter;
	color.channel[0] = 0;
	color.channel[(2 + fractol->a.color_shift) % 3 + 1] =\
		(int)(5.5 * pow((1 - t), 1) * pow(t, 2) * 255);
	color.channel[(0 + fractol->a.color_shift) % 3 + 1] =\
		(int)(15.5 * pow((1 - t), 2) * pow(t, 3) * 255);
	color.channel[(1 + fractol->a.color_shift) % 3 + 1] =\
		(int)(0.2 * pow((1 - t), 3) * t * 255);
	i = (cur.y * (int)ft_min(HEIGHT, WIDTH) + cur.x) * (int)sizeof(int);
	if (i < WIDTH * HEIGHT * sizeof(int))
	{
		fractol->mlx.image.img[i++] = color.channel[3];
		fractol->mlx.image.img[i++] = color.channel[2];
		fractol->mlx.image.img[i++] = color.channel[1];
		fractol->mlx.image.img[i] = color.channel[0];
	}
}

static void	reimage(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx.mlx_ptr, fractol->mlx.image.ptr);
	fractol->mlx.image.ptr = mlx_new_image(fractol->mlx.mlx_ptr, ft_min(WIDTH,\
	HEIGHT), ft_min(WIDTH, HEIGHT));
	fractol->mlx.image.img = (unsigned char *)mlx_get_data_addr(\
	fractol->mlx.image.ptr, &fractol->mlx.image.bps,\
	&fractol->mlx.image.size_line, &fractol->mlx.image.endian);
	ft_memset(fractol->mlx.image.img, 255, WIDTH * HEIGHT * sizeof(int));
}

static void	redraw_back(t_mlx *mlx)
{
	int 	i;

	i = 0;
	while (i < WIDTH * HEIGHT * (int)sizeof(int))
	{
		mlx->background.img[i++] = 50;
		mlx->background.img[i++] = 50;
		mlx->background.img[i++] = 50;
		mlx->background.img[i++] = 0;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->background.ptr,
						 0, 0);
}

void		mandel_my(t_fractol *fractol)
{
	t_point		cur;
	t_complex	c;
	t_complex	z;
	double		step;
	int			iter;

	reimage(fractol);
	cur = point_init(0, 0);
	//c = complex_init(-2 * fractol->a.scale, -2 * fractol->a.scale);
	c = complex_init(fractol->a.minx, fractol->a.miny);
	//step = fabs(c.re) / (ft_min(HEIGHT, WIDTH) / 2);
	step = fractol->a.size / fractol->a.img_size;
	//c.im += fractol->a.shift_y; //вверх-вниз
	//while (cur.y < ft_min(HEIGHT, WIDTH))
	while (cur.y < fractol->a.img_size)
	{
		cur.x = 0;
		//c.re = -2 * fractol->a.scale + fractol->a.shift_x;
		//влево-вправо
		c.re = fractol->a.minx;
		//while (cur.x < ft_min(HEIGHT, WIDTH))
		while (cur.x < fractol->a.img_size)
		{
			z = complex_init(0, 0);
			iter = 0;
			while (iter < fractol->a.max_iter)
			{
				iter++;
				z = complex_square(z);
				z = complex_sum(z, c);
				if (z.re * z.re + z.im * z.im > 4)
					break ;
			}
			color_init(cur, iter, fractol);
			cur.x++;
			c.re += step;
		}
		cur.y++;
		c.im += step;
	}
	redraw_back(&fractol->mlx);
	put_img_to_window_a(&fractol->mlx, 0, 0);
}
