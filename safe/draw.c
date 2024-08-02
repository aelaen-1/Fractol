/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:35:50 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/27 16:03:40 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//distinction car mandel n'est pas initialise
void	*draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			mandel(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (NULL);
}

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}


void	julia(t_fractal *f)
{
	int		i;
	double	tmp;

	f->name = "julia";
	f->zx = f->x / f->zoom + f->offset_x;
	f->zy = f->y / f->zoom + f->offset_y;
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
	f->cx = (f->x / f->zoom) + f->offset_x;
	f->cy = (f->y / f->zoom) + f->offset_y;
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