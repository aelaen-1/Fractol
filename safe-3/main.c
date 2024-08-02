/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:15:35 by aboukezi          #+#    #+#             */
/*   Updated: 2024/08/02 21:15:36 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractal *f)
{
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, HEIGHT, WIDTH, "fractol");
	f->image = mlx_new_image(f->mlx, HEIGHT, WIDTH);
	f->pxl_ptr = mlx_get_data_addr(f->image,
			&f->bpp,
			&f->line_len,
			&f->endian);
	f->x = 0;
	f->y = 0;
	f->color = 0xE72359;
	f->zoom = 200;
	f->shift_x = -2.0;
	f->shift_y = -2.0;
	f->iter = 42;
}

int	render(t_fractal *f, char *name)
{
	if (ft_strncmp(name, "mandel", 7) == 0)
		draw_mandelbrot(f);
	else if (ft_strncmp(name, "julia", 6) == 0)
		draw_julia(f);
	else
	{
		ft_putendl_fd("./fractol <mandel>/<ship>/'<julia> <real> <im>'", 1);
		byebye(f);
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	*f;

	f = malloc(sizeof(t_fractal));
	if (!f)
		return (0);
	if ((ac == 4 && !ft_strncmp(av[1], "julia", 6))
		|| (ac == 2 && !ft_strncmp(av[1], "mandel", 7)))
	{
		if (ac == 4)
		{
			f->cx = atodb(av[2]);
			f->cy = atodb(av[3]);
		}
		init(f);
		mlx_key_hook(f->window, key_handler, f);
		mlx_mouse_hook(f->window, mouse_handler, f);
		mlx_hook(f->window, 17, 0L, byebye, f);
		render(f, av[1]);
		mlx_loop(f->mlx);
	}
	else
		ft_putendl_fd("./fractol <mandel>/<ship>/'<julia> <real> <im>'", 1);
	return (0);
}
