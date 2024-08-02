/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:11:08 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/27 15:41:25 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *f, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		f->offset_x = (x / f->zoom + f->offset_x) - (x
				/ (f->zoom * zoom_level));
		f->offset_y = (y / f->zoom + f->offset_y) - (y
				/ (f->zoom * zoom_level));
		f->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		f->offset_x = (x / f->zoom + f->offset_x) - (x
				/ (f->zoom / zoom_level));
		f->offset_y = (y / f->zoom + f->offset_y) - (y
				/ (f->zoom / zoom_level));
		f->zoom /= zoom_level;
	}
	else
		return ;
}

int	key_handler(int key, t_fractal *fract)
{
	if (key == XK_Escape)
		exit(1);
	else if (key == XK_Left)
		fract->offset_x -= 42 / fract->zoom;
	else if (key == XK_Right)
		fract->offset_x += 42 / fract->zoom;
	else if (key == XK_Up)
		fract->offset_y -= 42 / fract->zoom;
	else if (key == XK_Down)
		fract->offset_y += 42 / fract->zoom;
	else if (key == ITER_PLUS)
		fract->iter += 10;
	else if (key == ITER_LESS)
		fract->iter -= 10;
	else if (key == COLOR)
		fract->color += 1000;
	draw_fractal(fract, fract->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}
