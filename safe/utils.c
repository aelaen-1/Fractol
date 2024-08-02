/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:27:37 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/17 18:35:55 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	putpixel(t_fractal *fractal, int x, int y, int color)
{
	int	*pixel;

	pixel = fractal->pxl_ptr;
	pixel[(y * fractal->line_len / 4) + x] = color;
}

int	byebye(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}