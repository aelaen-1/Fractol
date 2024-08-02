#include "fractol.h"

int	draw_fractal(t_fractal *fract, char *query)
{
	if (ft_strncmp(query, "mandel", 7) == 0)
		draw_mandelbrot(fract);
	else if (ft_strncmp(query, "julia", 6) == 0)
		draw_julia(fract);
	else if (ft_strncmp(query, "ship", 5) == 0)
		draw_burning_ship(fract);
	else
	{
		ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
		exit_fractal(fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->image, 0,
		0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	*fract;

	if (ac != 2 || ac != 4)
	{
		ft_putendl_fd("Retry with : mandel, burningship, julia <re> <im> ", 1);
		return (0);
	}

    if ((ac == 4) && !ft_strncmp(av[1], "julia", 5))
	{
		fract->cx = atodb(av[2]);
		fract->cy = atodb(av[3]);
	}
	fractal = malloc(sizeof(t_fractal));
	init(fract);
	mlx_key_hook(fract->window, key_hook, fractal);
	mlx_mouse_hook(fract->window, mouse_hook, fractal);
	mlx_hook(fract->window, 17, 0L, byebye, fractal);
	draw_fractal(fract, av[1]);
	mlx_loop(fract->mlx);
	return (0);
}