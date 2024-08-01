#include "fractol.h"

int byebye(t_fractal *fract)
{
    mlx_destroy_image(fract->mlx_ptr, fract->img.img_ptr);
    mlx_destroy_window(fract->mlx_ptr, fract->mlx_window);
    mlx_destroy_display(fract->mlx_ptr);
    free(fract->mlx_ptr);
    exit(EXIT_SUCCESS);
    return (0);
}

int keyHandler(int key, t_fractal *fract)
{
    if (key == XK_Escape)
        byebye(fract);
    else if (key == XK_Left)
        fract->shift_a -= (0.5 * fract->zoom);
    else if (key == XK_Right)
        fract->shift_a += (0.5 * fract->zoom);
    else if (key == XK_Down)
        fract->shift_b -= (0.5 * fract->zoom);
    else if (key == XK_Up)
        fract->shift_b += (0.5 * fract->zoom);
    else if (key == ITER_PLUS)
		fract->iter += 18;
	else if (key == ITER_LESS)	
		fract->iter-= 18;
    render(fract);
    return (0);
}

// int mouseHandler(int button, int x, int y, t_fractal *fract)
// {
//     if (button == ZOOM_IN)
//         fract->zoom +=0.05;
//     else if (button == ZOOM_OUT)
//         fract->zoom -=0.05;
//     render(fract);
//     printf("%d\n", button);
//     return (0);
// }

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

void	zoom(t_fractal *fract, int x, int y, int button)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (button == ZOOM_IN)
	{
		fract->shift_a = (x / fract->zoom + fract->shift_a) - (x
				/ (fract->zoom * zoom_level));
		fract->shift_b = (y / fract->zoom + fract->shift_b) - (y
				/ (fract->zoom * zoom_level));
		fract->zoom *= zoom_level;
	}
	else if (button == ZOOM_OUT)
	{
		fract->shift_a = (x / fract->zoom + fract->shift_a) - (x
				/ (fract->zoom / zoom_level));
		fract->shift_b = (y / fract->zoom + fract->shift_b) - (y
				/ (fract->zoom / zoom_level));
		fract->zoom /= zoom_level;
	}
	else
		return ;
}

int	mouse_hook(int button, int x, int y, t_fractal *fract)
{
	if (button == ZOOM_IN || button == ZOOM_OUT)
		zoom(fract, x, y, button);
	return (0);
}
