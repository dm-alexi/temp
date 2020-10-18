#include "fractol.h"

//int				zoom_m(int button, int x, int y, t_fractol *fractol)
//{
//	if (button == MOUSE_SCROLL_UP)
//		fractol->a.scale *= 0.9;
//	else
//		fractol->a.scale *= 1.1;
//
//}

//void				zoom_m(int key, t_fractol *fractol)
//{
//	if (key == MAIN_PLUS)
//		fractol->a.scale *= 0.9;
//	else
//		fractol->a.scale *= 1.1;
//	fractol->a.draw_algebraic[fractol->a.type](fractol);
//}


int				zoom_h(int key, int x, int y, t_fractol *fractol)
{
	double		wx;
	double		wy;

	wx = fractol->a.minx + x * fractol->a.size / fractol->a.img_size;
	wy = fractol->a.miny + y * fractol->a.size / fractol->a.img_size;

	if (key == MOUSE_SCROLL_DOWN)
	{
		fractol->a.minx = wx + (fractol->a.minx - wx) / SCALE;
		fractol->a.miny = wy + (fractol->a.miny - wy) / SCALE;
		fractol->a.size /= SCALE;
	}
	if (key == MOUSE_SCROLL_UP)
	{
		fractol->a.minx = wx + (fractol->a.minx - wx) * SCALE;
		fractol->a.miny = wy + (fractol->a.miny - wy) * SCALE;
		fractol->a.size *= SCALE;
	}
	fractol->a.draw_algebraic[fractol->a.type](fractol);
	return (0);
}