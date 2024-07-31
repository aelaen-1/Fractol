#include "fractol.h"

int byebye(t_fractal *fract)
{
    mlx_destroy_image(fract->mlx_ptr, fract->img.img_ptr);
    mlx_destroy_window(fract->mlx_ptr, fract->mlx_window);
    mlx_destroy_display(fract->mlx_ptr);
    free(fract->mlx_ptr);
    exit(EXIT_FAILURE);
    return (0);
}

int keyHandler(int key, t_fractal *fract)
{
    if (key == KEY_ESC)
        mlx_destroy_window(fract->mlx_ptr, fract->mlx_window);
    if (key == KEY_LEFT)
        fract->shift_a -= 20 / ((fract->zoom) * 0.9);
    if (key == KEY_RIGHT)
        fract->shift_a += 20 / ((fract->zoom) * 0.9);
    if (key == KEY_DOWN)
        fract->shift_b -= 20 / ((fract->zoom) * 0.9);
    if (key == KEY_UP)
        fract->shift_b += 20 / ((fract->zoom) * 0.9);
    render(fract);
    return (0);
}

int mouseHandler(int mousekey, t_fractal *fract)
{
    if (mousekey == SCROLL_UP)
        fract->zoom *= 1.05;
    if (mousekey == SCROLL_DOWN)
        fract->zoom *= 0.95;
    render(fract);
    return (0);
}

int	juliaTracking(int x, int y, t_fractal *fract)
{
	if (!ft_strncmp(fract->name, "julia", 5))
	{
		fract->julia_a = (scale(-2, 2, 0, WIDTH, x) * fract->zoom) + fract->shift_a;
		fract->julia_b = (scale(-2, 2, 0, HEIGHT, y) * fract->zoom) + fract->shift_b;
		render(fract);
	}
	return (0);
}
