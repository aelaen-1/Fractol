/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:38:24 by aboukezi          #+#    #+#             */
/*   Updated: 2024/08/02 14:38:25 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	drawer(t_fractal *fract, char *name)
{
	fract->x = 0;
	fract->y = 0;
	while (fract->x < SIZE)
	{
		while (fract->y < SIZE)
		{
			if (ft_strncmp(name, "mandel", 7) == 0)
				mandel(fract);
			else if (ft_strncmp(name, "julia", 6) == 0)
				julia(fract);
			fract->y++;
		}
		fract->x++;
		fract->y = 0;
	}
}

void	mandel(t_fractal *f)
{
	int		i;
	double	x_temp;

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
		pixel_put(f->x, f->y, f, 0x000000);
	else
		pixel_put(f->x, f->y, f, (f->color
				* i));
}

void	julia(t_fractal *f)
{
	int		i;
	double	tmp;

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
		pixel_put(f->x, f->y, f, 0x000000);
	else
		pixel_put(f->x, f->y, f, (f->color * (i
					% 255)));
}
