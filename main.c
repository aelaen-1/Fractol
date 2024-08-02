/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:38:38 by aboukezi          #+#    #+#             */
/*   Updated: 2024/08/02 14:38:39 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractal *fract)
{
	fract->mlx = mlx_init();
	fract->window = mlx_new_window(fract->mlx, SIZE, SIZE, "Fract-ol");
	fract->image = mlx_new_image(fract->mlx, SIZE, SIZE);
	fract->pointer_to_image = mlx_get_data_addr(fract->image,
			&fract->bits_per_pixel,
			&fract->size_line,
			&fract->endian);
	fract->x = 0;
	fract->y = 0;
	fract->shift_x = -2.66;
	fract->shift_y = -2.33;
	fract->iter = 30;
	fract->color = 0xE72359;
	fract->zoom = 150;
}

int	render(t_fractal *fract, char *name)
{
	if (ft_strncmp(name, "mandel", 7) == 0)
		drawer(fract, "mandel");
	else if (ft_strncmp(name, "julia", 6) == 0)
		drawer(fract, "julia");
	else
	{
		ft_putendl_fd("./fractol <mandel>/<ship>/'<julia> <real> <im>'", 1);
		byebye(fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->image, 0,
		0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fract;

	if ((ac == 4 && !ft_strncmp(av[1], "julia", 6))
		|| (ac == 2 && !ft_strncmp(av[1], "mandel", 7)))
	{
		if (ac == 4)
		{
			fract.cx = atodb(av[2]);
			fract.cy = atodb(av[3]);
		}
		init(&fract);
		mlx_key_hook(fract.window, key_handler, &fract);
		mlx_mouse_hook(fract.window, mouse_handler, &fract);
		mlx_hook(fract.window, 17, 0L, byebye, &fract);
		render(&fract, av[1]);
		mlx_loop(fract.mlx);
	}
	else
		ft_putendl_fd("./fractol <mandel>/<ship>/'<julia> <real> <im>'", 1);
	return (0);
}
