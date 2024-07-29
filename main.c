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
			fract.julia_a = atodouble(av[2]);
			fract.julia_b = atodouble(av[3]);
		}
		init(&fract);
		render(&fract);
		mlx_loop(fract.mlx_ptr); //corr 29/07 (&fract.mlx_ptr)
	}
	else
		error();
	return (0); 
}
