/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:38:49 by aboukezi          #+#    #+#             */
/*   Updated: 2024/08/02 14:38:50 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(int x, int y, t_fractal *fract, int color)
{
	int	*pixel;

	pixel = fract->pointer_to_image;
	pixel[(y * fract->size_line / 4) + x] = color;
}

int	byebye(t_fractal *fract)
{
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_destroy_window(fract->mlx, fract->window);
	free(fract->mlx);
	free(fract);
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
