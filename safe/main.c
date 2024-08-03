/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:55:04 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/27 16:03:52 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractal *fract)
{
	fract->mlx = mlx_init();
	fract->window = mlx_new_window(fract->mlx, SIZE, SIZE, "Fract-ol");
	fract->image = mlx_new_image(fract->mlx, SIZE, SIZE);
	fract->pxl_ptr = mlx_get_data_addr(fract->image,
			&fract->bpp,
			&fract->line_len,
			&fract->endian);
	fract->x = 0;
	fract->y = 0;
	fract->color = 0xE72359;
	fract->zoom = 300;
	fract->offset_x = -1.21;
	fract->offset_y = -1.21;
	fract->iter = 42;
	// fract->offset_x = -2.66;
	// fract->offset_y = -2.33;
	// fract->max_iterations = 30;
	// fract->color = 0xE72359;
	// fract->zoom = 300;
}

int	draw_fractal(t_fractal *fract, char *query)
{
	if (fract>type == MANDEL)
		draw_mandelbrot();
	if (ft_strncmp(query, "mandel", 7) == 0)
		draw_mandelbrot(fract);
	else if (ft_strncmp(query, "julia", 6) == 0)
	{
		if (!fract->cx && !fract->cy)
		{
			fract->cx = -0.745429;
			fract->cy = 0.05;
		}
		draw_julia(fract);
	}
	else
	{
		ft_putendl_fd("./fractol <mandel>/<ship>/'<julia> <real> <im>'", 1);
		byebye(fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->image, 0,
		0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fractol <fractal>", 1);
		ft_putendl_fd("Available fractals: mandelbrot, julia, burningship", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init(fractal);
	mlx_key_hook(fractal->window, key_handler, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, byebye, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
