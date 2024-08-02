#include "fractol.h"

void	put_color_to_pixel(t_fractal *fract, int x, int y, int color)
{
	int	*buffer;

	buffer = fract->pointer_to_image;
	buffer[(y * fract->size_line / 4) + x] = color;
}

/**
 * @brief    Exits the program.
 *
 * @param    fract
 */
int	exit_fractal(t_fractal *fract)
{
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_destroy_window(fract->mlx, fract->window);
	free(fract->mlx);
	free(fractal);
	exit(1);
	return (0);
}

/**
 * @brief    Generates a random double between -1.5 and 1.5.
 *
 * @return   double    The random double.
 */

/**
 * @brief    Increases or decreases the number of iterations.
 * The lower the number of iterations is, the faster the fractal is generated.
 *
 * @param    fract
 * @param    key_code
 */
void	change_iterations(t_fractal *fract, int key_code)
{
	if (key_code == M)
	{
		if (fract->max_iterations > 42)
			fract->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fract->max_iterations < 4200)
			fract->max_iterations += 42;
	}
}