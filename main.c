#include "fractol.h"

int main(int ac, char **av)
{
	t_fractal fract;

	if ((ac == 4 && !ft_strncmp(av[1], "julia", 5)) 
	|| (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)))
	{
		fract.name = av[1];
		if (ac == 4)
		{
			fract.julia_a = atodb(av[2]);
			fract.julia_b = atodb(av[3]);
		}
		init(&fract);
		render(&fract);
		mlx_loop(fract.mlx_ptr);
	}
	else
	{
		ft_putstr_fd("MALLOC ERROR", STDERR_FILENO);
    		exit(EXIT_FAILURE);
	}
	return (0); 
}
