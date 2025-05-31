/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:16:01 by aboukezi          #+#    #+#             */
/*   Updated: 2024/08/02 21:16:02 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	putpixel(t_fractal *f, int x, int y, int color)
{
	int	*pixel;

	pixel = f->pxl_ptr;
	pixel[(y * f->line_len / 4) + x] = color;
}

int	byebye(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->image);
	mlx_destroy_window(f->mlx, f->window);
	free(f->mlx);
	free(f);
	exit(1);
	return (0);
}

double	atodb(char *s)
{
	long	n;
	double	dec;
	double	coeff;
	int		sign;

	n = 0;
	dec = 0.0;
	coeff = 1;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		n = (n * 10) + *s++ - 48;
	if (*s == '.')
		++s;
	while (*s)
	{
		coeff /= 10;
		dec = dec + (*s++ - 48) * coeff;
	}
	return ((n + dec) * sign);
}
