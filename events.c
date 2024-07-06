#include "./include/fractol.h"

void byebye(t_fractal *fract)
{
    mlx_destroy_image(fract->mlx_ptr, fract->img.img_ptr);
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

    // refresh image 
    fractal_render(fract);
    return (0);
}

int mouseHandler(int mousekey, int x, int y, t_fractal *fract)
{
    if (mousekey == SCROLL_UP)
        fract->zoom *= 1.05;
    if (mousekey == SCROLL_DOWN)
        fract->zoom *= 0.95;
        // refresh image 
    fractal_render(fract);
    return (0);


}

int	juliaTracking(int x, int y, t_fractal *fract)
{
	if (!ft_strncmp(fract->name, "julia", 5))
	{
		fract->julia_a = (map(x, -2, +2, 0, WIDTH) * fract->zoom) + fract->shift_a;
		fract->julia_b = (map(y, +2, -2, 0, HEIGHT) * fract->zoom) + fract->shift_b;
		fractal_render(fract);
	}
	return 0;
}