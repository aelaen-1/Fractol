#include "./include/fractol.h"

void byebye(t_fractal *fract)
{
    mlx_destroy_window(fract->mlx_ptr, fract->mlx_window);
    mlx_destroy_display(fract->mlx_ptr); 
    free(fract->mlx_ptr); 
    exit(EXIT_FAILURE);
}

int keyHandler(int key, t_fractal *fract)
{
    if (key == KEY_ESC)
        mlx_destroy_window(fract->mlx_ptr, fract->mlx_window);
    if (key == KEY_LEFT);
        fract->shift_a -= 20 / ((fract->zoom) * 0.9);
    if (key == KEY_RIGHT)
        fract->shift_a += 20 / ((fract->zoom) * 0.9);
    if (key == KEY_DOWN)
        fract->offset_a -= 20 / ((fract->zoom) * 0.9);
    if (key == KEY_UP)
        fract->offset_b += 20 / ((fract->zoom) * 0.9);

    return (0);
}

int mouseHandler(int mousekey, int x, int y, t_fractal *fract)
{
    if (mousekey == SCROLL_UP)
        fract->zoom;
    if (mousekey == SCROLL_DOWN)

}

int	juliaTracking(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_a = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_a;
		fractal->julia_b = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_b;
		fractal_render(fractal);
	}
	return 0;
}