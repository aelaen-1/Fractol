

#include "fractol.h"
//distinction car mandel n'est pas initialise
void	*draw_mandelbrot(void *fractal_void)
{
	t_fractal	*f;

	f = (t_fractal *)fractal_void;
	f->x = 0;
	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			mandel(f);
			f->x++;
		}
		f->y++;
	}
	return (NULL);
}

void	draw_julia(t_fractal *f)
{
	f->x = 0;
	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			julia(f);
			f->x++;
		}
		f->y++;
	}
}


void	julia(t_fractal *f)
{
	int		i;
	double	tmp;

	f->name = "julia";
	f->zx = f->x / f->zoom + f->shift_x;
	f->zy = f->y / f->zoom + f->shift_y;
	i = 0;
	while (++i < f->iter)
	{
		tmp = f->zx;
		f->zx = f->zx * f->zx - f->zy * f->zy
			+ f->cx;
		f->zy = 2 * f->zy * tmp + f->cy;
		if (f->zx * f->zx + f->zy
			* f->zy >= __DBL_MAX__)
			break ;
	}
	if (i == f->iter)
		putpixel(f, f->x, f->y, 0x000000);
	else
		putpixel(f, f->x, f->y, (f->color * (i
					% 255)));
}

void	mandel(t_fractal *f)
{
	int		i;
	double	x_temp;

	f->name = "mandel";
	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (f->x / f->zoom) + f->shift_x;
	f->cy = (f->y / f->zoom) + f->shift_y;
	while (++i < f->iter)
	{
		x_temp = f->zx * f->zx - f->zy * f->zy
			+ f->cx;
		f->zy = 2. * f->zx * f->zy + f->cy;
		f->zx = x_temp;
		if (f->zx * f->zx + f->zy
			* f->zy >= __DBL_MAX__)
			break ;
	}
	if (i == f->iter)
		putpixel(f, f->x, f->y, 0x000000);
	else
		putpixel(f, f->x, f->y, (f->color
				* i));
}
