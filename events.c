/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:14:27 by aboukezi          #+#    #+#             */
/*   Updated: 2024/08/02 21:14:29 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *f, int x, int y, int zoom)
{
	double	speed;

	speed = 1.42;
	if (zoom == 1)
	{
		f->shift_x = (x / f->zoom + f->shift_x) - (x
				/ (f->zoom * speed));
		f->shift_y = (y / f->zoom + f->shift_y) - (y
				/ (f->zoom * speed));
		f->zoom *= speed;
	}
	else if (zoom == 0)
	{
		f->shift_x = (x / f->zoom + f->shift_x) - (x
				/ (f->zoom / speed));
		f->shift_y = (y / f->zoom + f->shift_y) - (y
				/ (f->zoom / speed));
		f->zoom /= speed;
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
	render(f, f->name);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *f)
{
	if (button == SCROLL_UP)
		zoom(f, x, y, 1);
	else if (button == SCROLL_DOWN)
		zoom(f, x, y, 0);
	render(f, f->name);
	return (0);
}
