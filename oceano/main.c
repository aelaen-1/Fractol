
#include "fractol.h"
#include "minilibx-linux/mlx.h"


int	main(int ac, char **av)
{
	t_fractal	fractal;



	if ((ac == 4 && !ft_strncmp(av[1], "julia", 5)) 
	|| (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodouble(av[2]);
			fractal.julia_y = atodouble(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
