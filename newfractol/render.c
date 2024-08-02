#include "fractol.h"


void	*draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fract;

	fract = (t_fractal *)fractal_void;
	fract->x = 0;
	fract->y = 0;
	while (fract->x < SIZE)
	{
		while (fract->y < SIZE)
		{
			calculate_mandelbrot(fract);
			fract->y++;
		}
		fract->x++;
		fract->y = 0;
	}
	return (NULL);
}

void	draw_julia(t_fractal *fractal)
{
	fract->x = 0;
	fract->y = 0;
	while (fract->x < SIZE)
	{
		while (fract->y < SIZE)
		{
			calculate_julia(fract);
			fract->y++;
		}
		fract->x++;
		fract->y = 0;
	}
}

void	draw_burning_ship(t_fractal *fract)
{
	fract->x = 0;
	fract->y = 0;
	while (fract->x < SIZE)
	{
		while (fract->y < SIZE)
		{
			calculate_burning_ship(fract);
			fract->y++;
		}
		fract->x++;
		fract->y = 0;
	}
}

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	fract->name = "mandel";
	i = 0;
	fract->zx = 0.0;
	fract->zy = 0.0;
	fract->cx = (fract->x / fract->zoom) + fract->offset_x;
	fract->cy = (fract->y / fract->zoom) + fract->offset_y;
	while (++i < fract->max_iterations)
	{
		x_temp = fract->zx * fract->zx - fract->zy * fract->zy
			+ fract->cx;
		fract->zy = 2. * fract->zx * fract->zy + fract->cy;
		fract->zx = x_temp;
		if (fract->zx * fract->zx + fract->zy
			* fract->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fract->max_iterations)
		put_color_to_pixel(fract, fract->x, fract->y, 0x000000);
	else
		put_color_to_pixel(fract, fract->x, fract->y, (fract->color * (i
					% 255)));
}

void	calculate_julia(t_fractal *fract)
{
	int		i;
	double	tmp;

	fract->name = "julia";
	fract->zx = fract->x / fract->zoom + fract->offset_x;
	fract->zy = fract->y / fract->zoom + fract->offset_y;
	i = 0;
	while (++i < fract->max_iterations)
	{
		tmp = fract->zx;
		fract->zx = fract->zx * fract->zx - fract->zy * fract->zy
			+ fract->cx;
		fract->zy = 2 * fract->zy * tmp + fract->cy;
		if (fract->zx * fract->zx + fract->zy
			* fract->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fract->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i
					% 255)));
}