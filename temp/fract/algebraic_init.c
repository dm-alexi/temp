#include "fractol.h"

void	algebaic_init(t_algebraic *fractol)
{
	fractol->max_iter = 70;
	fractol->color_shift = 130;
	fractol->type = 0;
	fractol->draw_algebraic[0] = &mandel_my;
//	fractol->draw_algebraic[0] = &create_mandelbrot;
	fractol->draw_algebraic[1] = &create_julia;
	fractol->scale = 1;
	fractol->shift_x = 0;
	fractol->shift_y = 0;
//	fractol->c = complex_init(-2, -2);
	fractol->img_size = ft_min(WIDTH, HEIGHT); // размер реального поля вывода фрактала
	fractol->minx = -2.0;			//
	fractol->miny = -2.0;			// координаты левого верхнего угла поля вывода
	fractol->size = 4.0;			// размер поля вывода
}

void	restore_to_default_a(t_fractol *fractol)
{
	fractol->a.max_iter = 50;
	fractol->a.color_shift = 0;
	fractol->a.type ? 0 : set_min_max(&fractol->a);
	ft_memset(fractol->mlx.image.img, 255, WIDTH * HEIGHT * sizeof(int));
	fractol->a.draw_algebraic[fractol->a.type](fractol);
}
