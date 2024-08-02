 

#include "fractol.h"

void	zoom(t_fractal *f, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		f->shift_x = (x / f->zoom + f->shift_x) - (x
				/ (f->zoom * zoom_level));
		f->shift_y = (y / f->zoom + f->shift_y) - (y
				/ (f->zoom * zoom_level));
		f->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		f->shift_x = (x / f->zoom + f->shift_x) - (x
				/ (f->zoom / zoom_level));
		f->shift_y = (y / f->zoom + f->shift_y) - (y
				/ (f->zoom / zoom_level));
		f->zoom /= zoom_level;
	}
	else
		return ;
}

int	key_handler(int key, t_fractal *f)
{
	if (key == XK_Escape)
		exit(1);
	else if (key == XK_Left)
		f->shift_x -= 42 / f->zoom;
	else if (key == XK_Right)
		f->shift_x += 42 / f->zoom;
	else if (key == XK_Up)
		f->shift_y -= 42 / f->zoom;
	else if (key == XK_Down)
		f->shift_y += 42 / f->zoom;
	else if (key == ITER_PLUS)
		f->iter += 10;
	else if (key == ITER_LESS)
		f->iter -= 10;
	else if (key == COLOR)
		f->color += 1000;
	draw_fractal(f, f->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *f)
{
	if (mouse_code == SCROLL_UP)
		zoom(f, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(f, x, y, -1);
	draw_fractal(f, f->name);
	return (0);
}
