/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:38:19 by aboukezi          #+#    #+#             */
/*   Updated: 2024/08/02 14:38:19 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *f, int x, int y, int zoom)
{
	double	speed;

	speed = 1.2;
	if (zoom == 1)
	{
		f->shift_x = (x / f->zoom + f->shift_x) - (x
				/ (f->zoom * speed));
		f->shift_y = (y / f->zoom + f->shift_y) - (y
				/ (f->zoom * speed));
		f->zoom *= speed;
	}
	else if (zoom == -1)
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

int	key_handler(int key, t_fractal *fract)
{
	if (key == XK_Escape)
		exit(1);
	else if (key == XK_Left)
		fract->shift_x -= 42 / fract->zoom;
	else if (key == XK_Right)
		fract->shift_x += 42 / fract->zoom;
	else if (key == XK_Up)
		fract->shift_y -= 42 / fract->zoom;
	else if (key == XK_Down)
		fract->shift_y += 42 / fract->zoom;
	else if (key == ITER_PLUS)
		fract->iter += 10;
	else if (key == ITER_LESS)
		fract->iter -= 10;
	else if (key == C)
		fract->color += 1000;
	printf("%d\n", key);
	render(fract, fract->name);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fract)
{
	if (button == SCROLL_UP)
		zoom(fract, x, y, 1);
	else if (button == SCROLL_DOWN)
		zoom(fract, x, y, -1);
	render(fract, fract->name);
	return (0);
}
